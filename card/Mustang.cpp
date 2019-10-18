#include "card/Mustang.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Mustang::name = "Mustang";
const string Mustang::feature = "Defend range increased to 1.";

Mustang::Mustang(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {
}

const std::string &Mustang::getName() {
    return Mustang::name;
}

const std::string &Mustang::getFeature() {
    return Mustang::feature;
}

const std::string &Mustang::getCardName() const {
    return Mustang::name;
}

const std::string &Mustang::getCardFeature() const {
    return Mustang::feature;
}

int Mustang::getAttackRange() const {
    return Mustang::attackRange;
}

int Mustang::getAddAttackRange() const {
    return Mustang::addAttackRange;
}

int Mustang::getDefendRange() const {
    return Mustang::defendRange;
}

bool Mustang::isMultiAttack() const {
    return Mustang::multiAttack;
}