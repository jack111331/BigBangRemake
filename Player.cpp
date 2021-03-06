#include <RoomManager.h>
#include <CharacterGenerator.h>
#include <vo/ChooseCharacterResponse.h>
#include <vo/UseCardRequest.h>
#include <vo/FoldCardResponse.h>
#include <Logger.h>
#include "Player.h"
#include "Room.h"
#include "User.h"
#include "Equipment.h"

using nlohmann::json;

std::string toString(Identity identity) {
    switch (identity) {
        case Identity::Sergeant: {
            return "Sergeant";
        }
        case Identity::ChiefSergeant: {
            return "ChiefSergeant";
        }
        case Identity::BadAss: {
            return "BadAss";
        }
        case Identity::Traitor: {
            return "Traitor";
        }
        case Identity::Unknown: {
            return "Unknown";
        }
        default: {
            return "Unknown";
        }
    }
}

Player::Player(Agent *agent) : agent(agent) {
    this->equipment = new Equipment();
}

void Player::handleMessage(const json &jsonMessage) {
    auto roomManager = RoomManager::getInstance();
    auto room = roomManager->searchRoom(this);
    auto logger = Logger::getLogger("[Player]");
    if (jsonMessage.find("card") != jsonMessage.end()) {
        uint32_t cardId = jsonMessage.at("card").at("id");
        if (cardId) {
            auto card = getCardInHoldingById(cardId);
            card->handleMessage(jsonMessage.at("card"));
        } else {
            logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
        }
    } else if (jsonMessage.find("chooseCharacter") != jsonMessage.end()) {
        Response::Player::ChooseCharacterResponse response = jsonMessage.at(
                "chooseCharacter").get<Response::Player::ChooseCharacterResponse>();
        this->character = CharacterGenerator::createCharacter(response.chooseCharacterName, room);
        for (auto player:room->getPlayerList()) {
            if (!player->getCharacter()) {
                return;
            }
        }
        room->changeRoomState(RoomState::PlayerCompleteChoosedCharacter);
    } else if (jsonMessage.find("useCard") != jsonMessage.end()) {
        if (room->isPlayerTurn(this)) {
            Request::Player::UseCardRequest request = jsonMessage.at("useCard").get<Request::Player::UseCardRequest>();
            room->useCard(request.cardId, room->getPositionByPlayer(this), request.targetPosition);
        }
    } else if (jsonMessage.find("endUsingCard") != jsonMessage.end()) {
        if (room->isPlayerTurn(this)) {
            room->changeRoomState(RoomState::PlayerCompleteUsedCard);
        }
    } else if (jsonMessage.find("foldCard") != jsonMessage.end()) {
        if (room->isPlayerTurn(this)) {
            Response::Player::FoldCardResponse response = jsonMessage.at(
                    "foldCard").get<Response::Player::FoldCardResponse>();
            for (auto cardId : response.cardIdList) {
                room->foldCard(cardId, room->getPositionByPlayer(this));
            }
            room->changeRoomState(RoomState::PlayerCompleteFoldedCard);
        }
    } else {
        logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
    }
}

void Player::informFinishUsingCard() {
    auto roomManager = RoomManager::getInstance();
    auto room = roomManager->searchRoom(this);
    room->changeRoomState(RoomState::PlayerCompleteUsedCard);
}

void Player::informFinishFoldingCard() {
    auto roomManager = RoomManager::getInstance();
    auto room = roomManager->searchRoom(this);
    room->changeRoomState(RoomState::PlayerCompleteFoldedCard);
}

void Player::addCardToHolding(Card *card) {
    holding.push_back(card);
}

Card *Player::getRandomHoldingCard() {
    auto it = holding.begin();
    srand(time(0));
    std::advance(it, rand() % static_cast<int>(holding.size()));
    return *it;
}

size_t Player::getHoldingCardAmount() const {
    return holding.size();
}

Card *Player::getCardInHoldingByName(const std::string &cardName) {
    for (auto &card : holding) {
        if (cardName == card->getCardName()) {
            return card;
        }
    }
    return nullptr;
}

Card *Player::getCardInHoldingById(uint32_t cardId) {
    for (auto &card : holding) {
        if (card->getId() == cardId) {
            return card;
        }
    }
    return nullptr;
}

void Player::removeCardInHolding(const Card *card) {
    for (auto it = holding.begin(); it != holding.end(); ++it) {
        if ((*it) == card) {
            holding.erase(it);
            this->dirty = true;
            break;
        }
    }
}

void Player::removeCardFromMyselfById(uint32_t cardId) {
    Card *card = getCardInHoldingById(cardId);
    if (card) {
        removeCardInHolding(card);
    }
}

Agent *Player::getAgent() const {
    return agent;
}

void Player::setIdentity(Identity identity) {
    this->identity = identity;
    this->dirty = true;
}

void Player::setCharacter(Character *character) {
    this->character = character;
    this->dirty = true;
}

void Player::setHp(int hp) {
    this->hp = hp;
    this->dirty = true;
}

void Player::setAttacked(bool attacked) {
    this->attacked = attacked;
    this->dirty = true;
}

void Player::setDead(bool dead) {
    this->dead = dead;
    this->dirty = true;
}

Identity Player::getIdentity() const {
    return identity;
}

Character *Player::getCharacter() const {
    return character;
}

Equipment *Player::getEquipment() const {
    return equipment;
}

int Player::getHp() const {
    return hp;
}

int Player::getMaxHp() const {
    return (character->getMaxHp() + (identity == Identity::Sergeant ? 1 : 0));
}

const std::vector<Card *> &Player::getHolding() const {
    return holding;
}

bool Player::isHasMultiAttack() const {
    return std::max(character->isHasMultiAttack(), equipment->isHasMultiAttack());
}

int Player::getAttackRange() const {
    return character->getAttackRange() + equipment->getAttackRange();
}

int Player::getAddAttackRange() const {
    return character->getAddAttackRange() + equipment->getAddAttackRange();
}

int Player::getDefendAttackRange() const {
    return character->getDefendAttackRange() + equipment->getDefendAttackRange();
}

bool Player::isAttacked() const {
    return attacked;
}

bool Player::isDead() const {
    return dead;
}

bool Player::isDirty() const {
    return dirty;
}

Player::~Player() {
    delete this->character;
    for (auto it = this->holding.begin(); it != this->holding.end(); ++it) {
        delete *it;
    }
    delete this->equipment;
}

