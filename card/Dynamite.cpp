#include "card/Dynamite.h"
#include <string>
#include "Room.h"
#include "Action.h"
#include "Equipment.h"

using std::string;
using namespace BangCard;

const string Dynamite::name = "Dynamite";
const string Dynamite::feature = "When equipped, draw card and determine if the drawed card is spade and its number is between 2~9, then dynamite will exploded and the player will loss 3 HP, otherwise this dynamite will send to player next to him.";

Dynamite::Dynamite(Room *room, int number, Suit suit) : EquipmentCard(room, number, suit) {
    this->listener = new GameEventListener();
    listener->onEquip = std::bind(&Dynamite::onEquip, this, std::placeholders::_1, std::placeholders::_2,
                                  std::placeholders::_3);
    listener->onUnequip = std::bind(&Dynamite::onUnequip, this, std::placeholders::_1, std::placeholders::_2,
                                    std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &Dynamite::getName() {
    return Dynamite::name;
}

const std::string &Dynamite::getCardName() const {
    return Dynamite::name;
}

const std::string &Dynamite::getFeature() {
    return Dynamite::feature;
}

const std::string &Dynamite::getCardFeature() const {
    return Dynamite::feature;
}

bool Dynamite::onEquip(Room *room, Card *card, Player *equiper) {
    listener->onPreDrawCard = std::bind(&Dynamite::onPreDrawCard, this, std::placeholders::_1, std::placeholders::_2);
}

bool Dynamite::onUnequip(Room *room, Card *card, Player *unequiper) {
    listener->onPreDrawCard = nullptr;
}

bool Dynamite::onPreDrawCard(Room *room, Player *drawer) {
    if (drawer->getEquipment()->isEquipmentCardExist(Dynamite::name)) {
        auto drawedCard = room->drawCardFromPlagueForDetermine();
        if (drawedCard->getSuit() == Suit::Spade && drawedCard->getNumber() >= 2 && drawedCard->getNumber() <= 9) {
            Action::lossHealth(room, drawer, drawer, 3);
        } else {
            auto nextPlayer = room->getNextPlayer(drawer);
            nextPlayer->getEquipment()->addEquipmentCard(this);
            drawer->getEquipment()->removeEquipmentCard(this);
        }
        room->putDetermineCardIntoPlague(drawedCard);
    }
    return true;
}

Dynamite::~Dynamite() {
    delete listener;
}