#include <algorithm>
#include <random>
#include <CharacterGenerator.h>
#include <Network.h>
#include <vo/WhoUseCardRequest.h>
#include <vo/WhoFoldCardRequest.h>
#include <vo/WhoGiveCardRequest.h>
#include <vo/ShowDetermineCardRequest.h>
#include <CardGenerator.h>
#include <card/Winchester.h>
#include <card/Barrel.h>
#include <card/Carabine.h>
#include <card/Mustang.h>
#include <card/Saloon.h>
#include <card/Schofield.h>
#include <card/Volcanic.h>
#include <card/Stagecoach.h>
#include <card/Wellsfargo.h>
#include <card/Jail.h>
#include <card/Bang.h>
#include <card/CatBalou.h>
#include <card/Gatling.h>
#include <card/Indians.h>
#include <card/Missed.h>
#include <card/Duel.h>
#include <card/Beer.h>
#include <card/Panic.h>
#include <card/Dynamite.h>
#include "Room.h"
#include "User.h"
#include "GameEventListener.h"
#include "vo/EndGameRequest.h"

Room::Room() {
    this->eventListener = new EventSubject();
    this->plague = new plague;
    this->discardPlague = new plague;
    this->roomState = RoomState::WaitPlayerToChooseCharacter;
    this->gameEndState = WinCondition::None;
}

bool Room::drawCard(position drawerPosition, size_t amount) {
    Player *drawer = getPlayerByPosition(drawerPosition);
    eventListener->notifyPreDrawCardEvent(this, drawer);
    for (size_t i = 0; i < amount; ++i) {
        if (plague->getPlagueCardAmount() == 0) {
            flushPlague();
        }
        Card *card = plague->chooseTopCard();
        plague->removeCardFromPlague(card);
        drawer->addCardToHolding(card);
    }
    return false;
}


bool Room::useCard(uint32_t cardId, position userPosition, position targetPosition) {
    Player *user = getPlayerByPosition(userPosition);
    Player *target = getPlayerByPosition(targetPosition);
    Card *card = user->getCardInHoldingById(cardId);
    auto network = Network::getInstance();
    if (card && card->useCardEffect(this, user, target)) {
        Request::Player::WhoUseCardRequest request = {cardId, userPosition, targetPosition};
        for (auto player : playerList) {
            if (getPositionByPlayer(player) != userPosition) {
                network->sendMessage(player->getAgent()->getToken(), nlohmann::json(request).dump());
            }
        }
        return true;
    }
    return false;
}

bool Room::foldCard(uint32_t cardId, position folderPosition) {
    Player *folder = getPlayerByPosition(folderPosition);
    Card *card = folder->getCardInHoldingById(cardId);
    auto network = Network::getInstance();
    if (card) {
        discardPlague->insertCardToPlague(card);
        folder->removeCardInHolding(card);
        Request::Player::WhoFoldCardRequest request = {cardId, folderPosition};
        for (auto player : playerList) {
            if (getPositionByPlayer(player) != folderPosition) {
                network->sendMessage(player->getAgent()->getToken(), nlohmann::json(request).dump());
            }
        }
        return true;
    }
    return false;
}

bool Room::giveCard(uint32_t cardId, position giverPosition, position receiverPosition) {
    Player *giver = getPlayerByPosition(giverPosition);
    Player *receiver = getPlayerByPosition(receiverPosition);
    Card *card = giver->getCardInHoldingById(cardId);
    auto network = Network::getInstance();
    if (card) {
        receiver->addCardToHolding(card);
        giver->removeCardInHolding(card);
        Request::Player::WhoGiveCardRequest request = {cardId, giverPosition, receiverPosition};
        for (auto player : playerList) {
            if (getPositionByPlayer(player) != giverPosition) {
                network->sendMessage(player->getAgent()->getToken(), nlohmann::json(request).dump());
            }
        }
        return true;
    }
    return false;
}

Card *Room::drawCardFromPlagueForDetermine() {
    if (plague->getPlagueCardAmount() == 0) {
        flushPlague();
    }
    Card *drawCard = plague->chooseTopCard();
    auto network = Network::getInstance();
    if (drawCard) {
        plague->removeCardFromPlague(drawCard);
        Request::Player::ShowDetermineCardRequest request = {drawCard->getId()};
        for (auto player : playerList) {
            network->sendMessage(player->getAgent()->getToken(), nlohmann::json(request).dump());
        }
    }
    return drawCard;
}

void Room::putDetermineCardIntoPlague(Card *card) {
    discardPlague->insertCardToPlague(card);
}


void Room::changeRoomState(RoomState roomState) {
    // TODO more state determine
    this->roomState = roomState;
}


void Room::flushPlague() {
    while (discardPlague->getPlagueCardAmount()) {
        Card *TopCard = discardPlague->chooseTopCard();
        plague->insertCardToPlague(TopCard);
        discardPlague->removeCardFromPlague(TopCard);
    }
    plague->flushPlague();
}

void Room::playerJoin(Agent *agent) {
    auto player = new Player(agent);
    agent->setPlayer(player);
    playerList.push_back(player);
}

WinCondition Room::isGameEnd() {
    int TeamSurviveAmount[4] = {};
    for (auto player : playerList) {
        if (!player->isDead()) {
            TeamSurviveAmount[static_cast<int>(player->getIdentity())]++;
        }
    }
    if (!TeamSurviveAmount[static_cast<int>(Identity::Sergeant)] &&
        !TeamSurviveAmount[static_cast<int>(Identity::ChiefSergeant)] &&
        !TeamSurviveAmount[static_cast<int>(Identity::BadAss)]) {
        return WinCondition::TraitorWin;
    } else if (!TeamSurviveAmount[static_cast<int>(Identity::Sergeant)]) {
        return WinCondition::BadAssWin;
    } else if (!TeamSurviveAmount[static_cast<int>(Identity::BadAss)] &&
               !TeamSurviveAmount[static_cast<int>(Identity::Traitor)]) {
        return WinCondition::SergeantWin;
    }
    return WinCondition::None;
}

void Room::autoChooseIdentity() {
    Identity teamDistribute[7] =
            {
                    Identity::Sergeant,
                    Identity::BadAss,
                    Identity::BadAss,
                    Identity::Traitor,
                    Identity::ChiefSergeant,
                    Identity::BadAss,
                    Identity::ChiefSergeant
            };
    std::shuffle(teamDistribute, teamDistribute + static_cast<int>(playerList.size()),
                 std::mt19937(std::random_device()()));
    int currentTeam = 0;
    for (auto &player : playerList) {
        player->setIdentity(teamDistribute[currentTeam++]);
    }
}

Player *Room::getNextPlayer(Player *currentPlayer) {
    int found = false;
    for (auto it = playerList.begin();; ++it) {
        if (it == playerList.end()) {
            it = playerList.begin();
        }
        if (found && !((*it)->isDead())) {
            return *it;
        }
        if (*it == currentPlayer) {
            found = true;
        }
    }
}

Player *Room::getPlayerByPosition(size_t position) {
    if (position >= playerList.size()) {
        return nullptr;
    }
    return playerList.at(position);
}

position Room::getPositionByPlayer(Player *targetPlayer) {
    for (size_t i = 0; i < playerList.size(); ++i) {
        if (playerList[i] == targetPlayer) {
            return i;
        }
    }
    return playerList.size();
}

bool Room::isPlayerTurn(Player *player) {
    return player == currentPlayer;
}


EventSubject *Room::getEventListener() const {
    return eventListener;
}

void Room::updatePlayerPublicInfo() {
    // TODO better design to update player's info
    //    for (auto it = playerList.begin(); it != playerList.end(); ++it) {
    //        (*it)->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapPublicGameInfo(this, *it).dump());
    //    }
}

void Room::initPlayerState() {
    for (auto it : playerList) {
        //setup initial hp
        it->setHp(it->getMaxHp());
        //give player corresponding card
        drawCard(getPositionByPlayer(it), it->getMaxHp());
    }
}

int Room::getDistance(Player *watcher, Player *watchee) {
    int minDistance = 666666;
    for (auto it = playerList.begin(); it != playerList.end(); ++it) {
        if ((*it) == watcher) {
            int distance = 1;
            for (auto itBegin = ++it;;) {
                if (itBegin == playerList.end()) {
                    itBegin = playerList.begin();
                }
                if ((*itBegin) == watchee) {
                    minDistance = std::min(minDistance, distance);
                    distance = 0;
                } else if ((*itBegin) == watcher) {
                    minDistance = std::min(minDistance, distance);
                    break;
                }
                if (!(*itBegin)->isDead()) {
                    distance++;
                }
                ++itBegin;
            }
            break;
        }
    }
    return std::max(0, minDistance + watchee->getAddAttackRange() - watcher->getDefendAttackRange());
}

size_t Room::getAlivePlayerAmount() {
    size_t AliveAmount = 0;
    for (auto player : playerList) {
        if (!player->isDead()) {
            AliveAmount++;
        }
    }
    return AliveAmount;
}

const std::vector<Player *> &Room::getPlayerList() const {
    return playerList;
}

size_t Room::getPlayerAmount() {
    return playerList.size();
}

void Room::setGameEndState(WinCondition gameEndState) {
    this->gameEndState = gameEndState;
}

void Room::resetPlayerRoundState(Player *player) {
    roomState = RoomState::WaitPlayerToUseCard;
    player->setAttacked(false);
}

void Room::sleepUntil(RoomState untilRoomState) {
    std::unique_lock<std::mutex> lock(mutex);
    conditionVariable.wait(lock, [this, untilRoomState] { return this->roomState == untilRoomState || this->roomState == RoomState::EndGame; });
}

void Room::startGame() {
    gameThread = std::thread(std::bind(&Room::gameLoop, this));
    gameThread.detach();
}

std::vector<Card *> Room::generateCardList() {
    std::vector<Card *> cardList;
    cardList.push_back(CardGenerator::createCard(BangCard::Winchester::getName(), this, 1, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Winchester::getName(), this, 7, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Barrel::getName(), this, 5, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Barrel::getName(), this, 8, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Carabine::getName(), this, 7, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Carabine::getName(), this, 2, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Mustang::getName(), this, 3, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Mustang::getName(),, this, 8, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Saloon::getName(), this, 12, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Saloon::getName(), this, 10, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Schofield::getName(), this, 13, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Schofield::getName(), this, 11, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Volcanic::getName(), this, 2, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Volcanic::getName(), this, 5, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Stagecoach::getName(), this, 8, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Stagecoach::getName(), this, 1, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Wellsfargo::getName(), this, 11, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Wellsfargo::getName(), this, 7, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Jail::getName(), this, 9, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Jail::getName(),, this, 4, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Bang::getName(), this, 5, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Bang::getName(), this, 6, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Bang::getName(), this, 7, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Bang::getName(), this, 8, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Missed::getName(), this, 9, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Missed::getName(), this, 10, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Missed::getName(), this, 11, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Missed::getName() this, 12, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Indians::getName(), this, 9, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Indians::getName(), this, 4, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Gatling::getName(), this, 9, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Gatling::getName(), this, 9, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::Duel::getName(), this, 3, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Duel::getName(), this, 4, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Beer::getName(), this, 9, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::Beer::getName(), this, 10, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Panic::getName(), this, 1, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Panic::getName(), this, 7, Suit::Heart));
    cardList.push_back(CardGenerator::createCard(BangCard::CatBalou::getName(), this, 2, Suit::Spade));
    cardList.push_back(CardGenerator::createCard(BangCard::CatBalou::getName(), this, 9, Suit::Club));
    cardList.push_back(CardGenerator::createCard(BangCard::Dynamite::getName(), this, 4, Suit::Diamond));
    cardList.push_back(CardGenerator::createCard(BangCard::Dynamite::getName(), this, 3, Suit::Heart));
}


void Room::initGame() {
    std::vector<Card *> cardList = generateCardList();

    plague->init(cardList);

    // auto choose team for player
    autoChooseIdentity();

    // let player choose character
    // generate 2 random character, this two can't be identical
    roomState = RoomState::WaitPlayerToChooseCharacter;
    auto characterPool = new RandomCharacterPool();
    for (auto player : playerList) {
        playerService->sendRetrieveGameInfoRequest(player, this, playerList, cardList);
        characterPool->flushChoicePool();
        // Hard code to have 2 character
        playerService->sendChooseCardRequest(player, characterPool->choiceCharacterFromPool());
        characterPool->removeChoiceFromPool();
    }
    delete characterPool;

    // loop to check if everybody has character card
    sleepUntil(RoomState::PlayerCompleteChoosedCharacter);
    roomState = RoomState::StartGame;


    // choose Sergent as the first player
    for (auto player : playerList) {
        if (player->getIdentity() == Identity::Sergeant) {
            currentPlayer = player;
            break;
        }
    }
    initPlayerState();
}

void Room::endGame(WinCondition endGameState) {
    auto network = Network::getInstance();
    std::vector<Player *> winnerList, loserList;
    for (auto player : playerList) {
        if (endGameState == WinCondition::SergeantWin) {
            if (player->getIdentity() == Identity::Sergeant || player->getIdentity() == Identity::ChiefSergeant) {
                winnerList.push_back(player);
            } else {
                loserList.push_back(player);
            }
        } else if (endGameState == WinCondition::BadAssWin) {
            if (player->getIdentity() == Identity::BadAss) {
                winnerList.push_back(player);
            } else {
                loserList.push_back(player);
            }
        } else if (endGameState == WinCondition::TraitorWin) {
            if (player->getIdentity() == Identity::Traitor) {
                winnerList.push_back(player);
            } else {
                loserList.push_back(player);
            }
        }
    }
    for (auto winner : winnerList) {
        Request::Player::EndGameRequest request = {true};
        network->sendMessage(winner->getAgent()->getToken(), nlohmann::json(request).dump());
    }
    for (auto loser : loserList) {
        Request::Player::EndGameRequest request = {false};
        network->sendMessage(loser->getAgent()->getToken(), nlohmann::json(request).dump());
    }
}

void Room::gameLoop() {
    initGame();

    // Loop while game isn't end, gameEndState record what team win
    while ((gameEndState = isGameEnd()) == WinCondition::None) {
        // Draw card stage
        currentPlayer->getCharacter()->drawCard(this, currentPlayer);

        //        updatePlayerPublicInfo();
        // Inform user that it's his/her turn
        roomState = RoomState::WaitPlayerToUseCard;
        playerService->sendInformUseCardRequest(currentPlayer);
        sleepUntil(RoomState::PlayerCompleteUsedCard);//end using card

        if(roomState == RoomState::EndGame) {
            break;
        }
        while (currentPlayer->getHoldingCardAmount() > currentPlayer->getHp()) {
            roomState = RoomState::WaitPlayerToFoldCard;
            playerService->sendInformFoldCardRequest(currentPlayer);
            sleepUntil(RoomState::PlayerCompleteFoldedCard);//fold card
            updatePlayerPublicInfo();
        }
        // Reset player's state
        resetPlayerRoundState(currentPlayer);
        eventListener->notifyRoundEndEvent(this, currentPlayer);
        currentPlayer = getNextPlayer(currentPlayer);
    }
    endGame(gameEndState);
}

Room::~Room() {
    for (auto it = playerList.begin(); it != playerList.end();) {
        delete *it;
    }
    delete this->plague;
    delete this->discardPlague;
    delete this->eventListener;
    delete this->playerService;
}
