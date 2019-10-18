#include "character/ElGringo.h"
#include <string>
#include "Player.h"
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string ElGringo::name = "El Gringo";
const string ElGringo::feature = "When loss blood, draw one card from attacker.";

ElGringo::ElGringo(Room *room) : Character(room) {
    this->listener = new GameEventListener();
    listener->onLossBlood = std::bind(&ElGringo::onLossBlood, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &ElGringo::getName() {
    return ElGringo::name;
}

const std::string &ElGringo::getCharacterName() const {
    return ElGringo::name;
}

const std::string &ElGringo::getFeature() {
    return ElGringo::feature;
}

const std::string &ElGringo::getCharacterFeature() const {
    return ElGringo::feature;
}

int ElGringo::getMaxHp() const {
    return ElGringo::maxHp;
}

int ElGringo::getAttackRange() const {
    return ElGringo::attackRange;
}

int ElGringo::getAddAttackRange() const {
    return ElGringo::addRange;
}

int ElGringo::getDefendAttackRange() const {
    return ElGringo::defendRange;
}

bool ElGringo::isHasMultiAttack() const {
    return ElGringo::hasMultiAttack;
}

void ElGringo::onLossBlood(Room *room, Player *loser, Player *attacker) {
    // TODO inform random choose card
    auto card = attacker->getRandomHoldingCard();
    room->giveCard(card->getId(), room->getPositionByPlayer(attacker), room->getPositionByPlayer(loser));
}

ElGringo::~ElGringo() {
    delete listener;
}
