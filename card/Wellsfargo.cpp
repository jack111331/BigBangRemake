#include "card/Wellsfargo.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Wellsfargo::name = "Wells fargo";
const string Wellsfargo::feature = "Draw 3 card from plague.";

Wellsfargo::Wellsfargo(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Wellsfargo::getName() {
    return Wellsfargo::name;
}

const std::string &Wellsfargo::getCardName() const {
    return Wellsfargo::name;
}

const std::string &Wellsfargo::getFeature() {
    return Wellsfargo::feature;
}

const std::string &Wellsfargo::getCardFeature() const {
    return Wellsfargo::feature;
}

bool Wellsfargo::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    constexpr int drawCardAmount = 3;
    room->drawCard(room->getPositionByPlayer(myself), drawCardAmount);

    return true;
}
