#include "Card.h"
#include "Room.h"

using std::string;

uint32_t Card::cardId = 0;

Card::Card(Room *room, int number, Suit suit) : number(number), suit(suit) {
    this->id = cardId++;
}


bool Card::useCardEffect(Room *room, Player *myself, Player *target) {
    room->foldCard(getId(), room->getPositionByPlayer(myself));
    return true;
}

int Card::getNumber() const {
    return number;
}

void Card::setNumber(int number) {
    this->number = number;
}

Suit Card::getSuit() const {
    return suit;
}

void Card::setSuit(Suit suit) {
    this->suit = suit;
}

uint32_t Card::getId() const {
    return id;
}

Card::~Card() {

}