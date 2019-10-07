#include "character/PaulRegret.h"
#include <string>
#include "Room.h"


using std::string;
using namespace BangCharacter;

const string PaulRegret::name = "Paul Regret";
const string PaulRegret::feature = "Add 1 attack range.";

PaulRegret::PaulRegret(Room *room) : Character(room) {
}

const std::string &PaulRegret::getName() {
    return PaulRegret::name;
}

const std::string &PaulRegret::getCharacterName() const {
    return PaulRegret::name;
}

const std::string &PaulRegret::getFeature() {
    return PaulRegret::feature;
}

const std::string &PaulRegret::getCharacterFeature() const {
    return PaulRegret::feature;
}

int PaulRegret::getMaxHp() const {
    return PaulRegret::maxHp;
}

int PaulRegret::getAttackRange() const {
    return PaulRegret::attackRange;
}

int PaulRegret::getAddRange() const {
    return PaulRegret::addRange;
}

int PaulRegret::getDefendRange() const {
    return PaulRegret::defendRange;
}

bool PaulRegret::isHasMultiAttack() const {
    return PaulRegret::hasMultiAttack;
}

