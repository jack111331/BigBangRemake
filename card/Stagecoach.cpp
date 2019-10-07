#include "card/Stagecoach.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Stagecoach::name = "Stagecoach";
const string Stagecoach::feature = "Draw 2 card from plague.";

Stagecoach::Stagecoach(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Stagecoach::getName() {
    return Stagecoach::name;
}

const std::string &Stagecoach::getCardName() const {
    return Stagecoach::name;
}

const std::string &Stagecoach::getFeature() {
    return Stagecoach::feature;
}

const std::string &Stagecoach::getCardFeature() const {
    return Stagecoach::feature;
}

bool Stagecoach::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    constexpr int drawCardAmount = 2;
    room->drawCard(room->getPositionByPlayer(myself), drawCardAmount);
    return true;
}
