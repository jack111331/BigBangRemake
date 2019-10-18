#include "character/SuzyLafayette.h"
#include <string>
#include "Player.h"
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string SuzyLafayette::name = "Suzy Lafayette";
const string SuzyLafayette::feature = "When you end round with no holding left, draw one card from plague.";


SuzyLafayette::SuzyLafayette(Room *room) : Character(room) {

    this->listener = new GameEventListener();
    listener->onLossBlood = std::bind(&SuzyLafayette::onRoundEnd, this, std::placeholders::_1, std::placeholders::_2);
    room->getEventListener()->subscribe(listener);
}

const std::string &SuzyLafayette::getName() {
    return SuzyLafayette::name;
}

const std::string &SuzyLafayette::getCharacterName() const {
    return SuzyLafayette::name;
}

const std::string &SuzyLafayette::getFeature() {
    return SuzyLafayette::feature;
}

const std::string &SuzyLafayette::getCharacterFeature() const {
    return SuzyLafayette::feature;
}

int SuzyLafayette::getMaxHp() const {
    return SuzyLafayette::maxHp;
}

int SuzyLafayette::getAttackRange() const {
    return SuzyLafayette::attackRange;
}

int SuzyLafayette::getAddAttackRange() const {
    return SuzyLafayette::addRange;
}

int SuzyLafayette::getDefendAttackRange() const {
    return SuzyLafayette::defendRange;
}

bool SuzyLafayette::isHasMultiAttack() const {
    return SuzyLafayette::hasMultiAttack;
}

void SuzyLafayette::onRoundEnd(Room *room, Player *roundEnder) {
    if (!roundEnder->getHoldingCardAmount()) {
        room->drawCard(room->getPositionByPlayer(roundEnder), 1);
    }
}

SuzyLafayette::~SuzyLafayette() {
    delete listener;
}
