#include "character/RoseDoolan.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string RoseDoolan::name = "Rose Doolan";
const string RoseDoolan::feature = "Add 1 defend range.";

RoseDoolan::RoseDoolan(Room *room) : Character(room) {
}

const std::string &RoseDoolan::getName() {
    return RoseDoolan::name;
}

const std::string &RoseDoolan::getCharacterName() const {
    return RoseDoolan::name;
}

const std::string &RoseDoolan::getFeature() {
    return RoseDoolan::feature;
}

const std::string &RoseDoolan::getCharacterFeature() const {
    return RoseDoolan::feature;
}

int RoseDoolan::getMaxHp() const {
    return RoseDoolan::maxHp;
}

int RoseDoolan::getAttackRange() const {
    return RoseDoolan::attackRange;
}

int RoseDoolan::getAddAttackRange() const {
    return RoseDoolan::addRange;
}

int RoseDoolan::getDefendAttackRange() const {
    return RoseDoolan::defendRange;
}

bool RoseDoolan::isHasMultiAttack() const {
    return RoseDoolan::hasMultiAttack;
}
