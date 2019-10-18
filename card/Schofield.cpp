#include "card/Schofield.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Schofield::name = "Schofield";
const string Schofield::feature = "Attack range increased to 2.";

Schofield::Schofield(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {
}

const std::string &Schofield::getName() {
    return Schofield::name;
}

const std::string &Schofield::getCardName() const {
    return Schofield::name;
}

const std::string &Schofield::getFeature() {
    return Schofield::feature;
}

const std::string &Schofield::getCardFeature() const {
    return Schofield::feature;
}

int Schofield::getAttackRange() const {
    return Schofield::attackRange;
}

int Schofield::getAddAttackRange() const {
    return Schofield::addAttackRange;
}

int Schofield::getDefendRange() const {
    return Schofield::defendRange;
}

bool Schofield::isMultiAttack() const {
    return Schofield::multiAttack;
}