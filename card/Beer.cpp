#include "card/Beer.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Beer::name = "Beer";
const string Beer::feature = "On your turn, drink beer to recover 1 HP under Max HP. Not on your turn, when you are about to die, drink it immediately.";

Beer::Beer(Room *room, int number, Suit suit) : Card(room, number, suit) {
    this->listener = new GameEventListener();
    listener->onLossBlood = std::bind(&Beer::onLossBlood, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &Beer::getName() {
    return Beer::name;
}

const std::string &Beer::getCardName() const {
    return Beer::name;
}

const std::string &Beer::getFeature() {
    return Beer::feature;
}

const std::string &Beer::getCardFeature() const {
    return Beer::feature;
}

bool Beer::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    Action::recoverHealth(myself, 1);
    room->getEventListener()->unsubscribe(listener);
    return true;
}

void Beer::onLossBlood(Room *room, Player *loser, Player *attacker) {
    if (loser->getHp() == 1 && room->getAlivePlayerAmount() > 2) {
        useCardEffect(room, loser, nullptr);
    }
}

Beer::~Beer() {
    delete listener;
}
