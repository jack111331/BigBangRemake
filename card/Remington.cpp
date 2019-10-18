#include "card/Remington.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Remington::name = "Remington";
const string Remington::feature = "Attack range increased to 3.";

Remington::Remington(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {
}

const std::string &Remington::getName() {
    return Remington::name;
}

const std::string &Remington::getCardName() const {
    return Remington::name;
}

const std::string &Remington::getFeature() {
    return Remington::feature;
}

const std::string &Remington::getCardFeature() const {
    return Remington::feature;
}

int Remington::getAttackRange() const {
    return Remington::attackRange;
}

int Remington::getAddAttackRange() const {
    return Remington::addAttackRange;
}

int Remington::getDefendRange() const {
    return Remington::defendRange;
}

bool Remington::isMultiAttack() const {
    return Remington::multiAttack;
}