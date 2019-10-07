#include "character/BartCassidy.h"
#include <string>
#include "Player.h"
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string BartCassidy::name = "Bart Cassidy";
const string BartCassidy::feature = "Draw one card from plague while HP decrease one point.";

BartCassidy::BartCassidy(Room *room) : Character(room) {
    this->listener = new GameEventListener();
    listener->onLossBlood = std::bind(&BartCassidy::onLossBlood, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &BartCassidy::getName() {
    return BartCassidy::name;
}

const std::string &BartCassidy::getCharacterName() const {
    return BartCassidy::name;
}

const std::string &BartCassidy::getFeature() {
    return BartCassidy::feature;
}

const std::string &BartCassidy::getCharacterFeature() const {
    return BartCassidy::feature;
}

int BartCassidy::getMaxHp() const {
    return BartCassidy::maxHp;
}

int BartCassidy::getAttackRange() const {
    return BartCassidy::attackRange;
}

int BartCassidy::getAddRange() const {
    return BartCassidy::addRange;
}

int BartCassidy::getDefendRange() const {
    return BartCassidy::defendRange;
}

bool BartCassidy::isHasMultiAttack() const {
    return BartCassidy::hasMultiAttack;
}

void BartCassidy::onLossBlood(Room *room, Player *loser, Player *attacker) {
    room->drawCard(room->getPositionByPlayer(loser), 1);
}

BartCassidy::~BartCassidy() {
    delete listener;
}
