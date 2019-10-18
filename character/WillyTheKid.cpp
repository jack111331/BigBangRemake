#include "character/WillyTheKid.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string WillyTheKid::name = "Willy The Kid";
const string WillyTheKid::feature = "Add multi attack ability.";

WillyTheKid::WillyTheKid(Room *room) : Character(room) {
}

const std::string &WillyTheKid::getName() {
    return WillyTheKid::name;
}

const std::string &WillyTheKid::getCharacterName() const {
    return WillyTheKid::name;
}

const std::string &WillyTheKid::getFeature() {
    return WillyTheKid::feature;
}

const std::string &WillyTheKid::getCharacterFeature() const {
    return WillyTheKid::feature;
}

int WillyTheKid::getMaxHp() const {
    return WillyTheKid::maxHp;
}

int WillyTheKid::getAttackRange() const {
    return WillyTheKid::attackRange;
}

int WillyTheKid::getAddAttackRange() const {
    return WillyTheKid::addRange;
}

int WillyTheKid::getDefendAttackRange() const {
    return WillyTheKid::defendRange;
}

bool WillyTheKid::isHasMultiAttack() const {
    return WillyTheKid::hasMultiAttack;
}
