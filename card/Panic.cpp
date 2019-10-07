#include "card/Panic.h"
#include <string>
#include "Room.h"
#include "Action.h"
//#include "DrawCardFactory.h"


using std::string;
using namespace BangCard;

const string Panic::name = "Panic!";
const string Panic::feature = "Choose one card of one player whose distance between you under 1.";

Panic::Panic(Room *room, int number, Suit suit) : Card(room, number, suit) {
}


const std::string &Panic::getName() {
    return Panic::name;
}

const std::string &Panic::getCardName() const {
    return Panic::name;
}

const std::string &Panic::getFeature() {
    return Panic::feature;
}

const std::string &Panic::getCardFeature() const {
    return Panic::feature;
}

bool Panic::useCardEffect(Room *room, Player *myself, Player *target) {
    if (room->getDistance(myself, target) <= 1) {
        if (!Card::useCardEffect(room, myself, target)) {
            return false;
        }
        //        CDrawCardFromPlayer *DrawCard = new CDrawCardFromPlayer(NSDrawCardFactory::DrawCard("Choose Card"));
        //        DrawCard->DrawCardFromPlayer(myself, target);
        //        delete DrawCard;
        return true;
    }
    return false;
}
