#include "card/Volcanic.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Volcanic::name = "Volcanic";
const string Volcanic::feature = "Attack range is 1, player can multi attack others.";

Volcanic::Volcanic(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {

}

const std::string &Volcanic::getName() {
    return Volcanic::name;
}

const std::string &Volcanic::getCardName() const {
    return Volcanic::name;
}

const std::string &Volcanic::getFeature() {
    return Volcanic::feature;
}

const std::string &Volcanic::getCardFeature() const {
    return Volcanic::feature;
}

int Volcanic::getAttackRange() const {
    return Volcanic::attackRange;
}

int Volcanic::getAddAttackRange() const {
    return Volcanic::addAttackRange;
}

int Volcanic::getDefendRange() const {
    return Volcanic::defendRange;
}

bool Volcanic::isMultiAttack() const {
    return Volcanic::multiAttack;
}
