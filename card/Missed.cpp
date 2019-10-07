#include "card/Missed.h"
#include <string>
#include "Room.h"

using std::string;
using namespace BangCard;

const string Missed::name = "Missed!";
const string Missed::feature = "When not on your round, dodge one bang! attack.";


Missed::Missed(Room *room, int number, Suit suit) : Card(room, number, suit) {
}


const std::string &Missed::getName() {
    return Missed::name;
}

const std::string &Missed::getCardName() const {
    return Missed::name;
}

const std::string &Missed::getFeature() {
    return Missed::feature;
}

const std::string &Missed::getCardFeature() const {
    return Missed::feature;
}