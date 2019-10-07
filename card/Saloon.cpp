#include "card/Saloon.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Saloon::name = "Saloon";
const string Saloon::feature = "Recover all alived player 1 HP.";

Saloon::Saloon(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Saloon::getName() {
    return Saloon::name;
}

const std::string &Saloon::getCardName() const {
    return Saloon::name;
}

const std::string &Saloon::getFeature() {
    return Saloon::feature;
}

const std::string &Saloon::getCardFeature() const {
    return Saloon::feature;
}

bool Saloon::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    auto playerList = room->getPlayerList();
    for (auto player : playerList) {
        if (!player->isDead()) {
            Action::recoverHealth(player, 1);
        }
    }
    return true;
}
