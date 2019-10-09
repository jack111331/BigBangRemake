#include <RoomManager.h>
#include "Player.h"
#include "Room.h"
#include "User.h"
#include "Equipment.h"

using nlohmann::json;

Player::Player(Agent *agent) : agent(agent) {

}

void Player::handleMessage(const json &jsonMessage) {
    //TODO handle message
    if(jsonMessage.at("card")) {
        uint32_t cardId = jsonMessage.at("card").at("id");
        if(cardId) {
            auto card = getCardInHoldingById(cardId);
            card->handleMessage(jsonMessage.at("card"));
        } else {
            // TODO report error
        }
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

void Player::changeEquipment(Equipment *equipment) {
    this->equipment = equipment;
}

Agent *Player::getAgent() const {
    return agent;
}

void Player::setIdentity(Team identity) {
    this->identity = identity;
}

void Player::setCharacter(Character *character) {
    this->character = character;
}

void Player::setEquipment(Equipment *equipment) {
    this->equipment = equipment;
}

void Player::setHp(int hp) {
    this->hp = hp;
}

void Player::setAttacked(bool attacked) {
    this->attacked = attacked;
}

void Player::setDead(bool dead) {
    this->dead = dead;
}

Team Player::getIdentity() const {
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
    return (character->getMaxHp() + (identity == Team::Sergeant ? 1 : 0));
}

const std::vector<Card *> &Player::getHolding() const {
    return holding;
}

bool Player::isHasMultiAttack() const {

}

int Player::getAttackRange() const {

}

int Player::getAddAttackRange() const {

}

int Player::getDefendAttackRange() const {

}

bool Player::isAttacked() const {
    return attacked;
}

bool Player::isDead() const {
    return dead;
}

Player::~Player() {
    delete this->character;
    for (auto it = this->holding.begin(); it != this->holding.end(); ++it) {
        delete *it;
    }
    delete this->equipment;
}

