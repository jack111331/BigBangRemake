#include "card/Carabine.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Carabine::name = "Carabine";
const string Carabine::feature = "Attack range increased to 4.";

Carabine::Carabine(Room *room, int number, Suit suit) : WeaponCard(room, number, suit) {
}

const std::string &Carabine::getName() {
    return Carabine::name;
}

const std::string &Carabine::getCardName() const {
    return Carabine::name;
}

const std::string &Carabine::getFeature() {
    return Carabine::feature;
}

const std::string &Carabine::getCardFeature() const {
    return Carabine::feature;
}

int Carabine::getAttackRange() const {
    return Carabine::attackRange;
}

int Carabine::getAddAttackRange() const {
    return Carabine::addAttackRange;
}

int Carabine::getDefendRange() const {
    return Carabine::defendRange;
}

bool Carabine::isMultiAttack() const {
    return Carabine::multiAttack;
}
