#include "card/Winchester.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Winchester::name = "Winchester";
const string Winchester::feature = "Attack range increased to 5.";

Winchester::Winchester(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {
}

const std::string &Winchester::getName() {
    return Winchester::name;
}

const std::string &Winchester::getCardName() const {
    return Winchester::name;
}

const std::string &Winchester::getFeature() {
    return Winchester::feature;
}

const std::string &Winchester::getCardFeature() const {
    return Winchester::feature;
}

int Winchester::getAttackRange() const {
    return Winchester::attackRange;
}

int Winchester::getAddAttackRange() const {
    return Winchester::addAttackRange;
}


int Winchester::getDefendRange() const {
    return Winchester::defendRange;
}

bool Winchester::isMultiAttack() const {
    return Winchester::multiAttack;
}