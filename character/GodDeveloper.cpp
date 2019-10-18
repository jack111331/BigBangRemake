#include "character/GodDeveloper.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string GodDeveloper::name = "God Developer";
const string GodDeveloper::feature = "No Effect, just have more HP and multi attack(?.";

GodDeveloper::GodDeveloper(Room *room) : Character(room) {
}

const std::string &GodDeveloper::getName() {
    return GodDeveloper::name;
}

const std::string &GodDeveloper::getCharacterName() const {
    return GodDeveloper::name;
}

const std::string &GodDeveloper::getFeature() {
    return GodDeveloper::feature;
}

const std::string &GodDeveloper::getCharacterFeature() const {
    return GodDeveloper::feature;
}

int GodDeveloper::getMaxHp() const {
    return GodDeveloper::maxHp;
}

int GodDeveloper::getAttackRange() const {
    return GodDeveloper::attackRange;
}

int GodDeveloper::getAddAttackRange() const {
    return GodDeveloper::addRange;
}

int GodDeveloper::getDefendAttackRange() const {
    return GodDeveloper::defendRange;
}

bool GodDeveloper::isHasMultiAttack() const {
    return GodDeveloper::hasMultiAttack;
}
