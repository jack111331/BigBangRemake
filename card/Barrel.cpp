#include "card/Barrel.h"
#include <string>
#include "Room.h"
#include "GameEventListener.h"
#include "Equipment.h"

using std::string;
using namespace BangCard;

const string Barrel::name = "Barrel";
const string Barrel::feature = "When attacked, draw a card and determine whether it is heart. If so, then missed this attack.";

Barrel::Barrel(Room *room, int number, Suit suit) : EquipmentCard(room, number, suit) {
    this->listener = new GameEventListener();
    listener->onEquip = std::bind(&Barrel::onEquip, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    listener->onUnequip = std::bind(&Barrel::onUnequip, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &Barrel::getName() {
    return Barrel::name;
}

const std::string &Barrel::getCardName() const {
    return Barrel::name;
}

const std::string &Barrel::getFeature() {
    return Barrel::feature;
}

const std::string &Barrel::getCardFeature() const {
    return Barrel::feature;
}

bool Barrel::onEquip(Room *room, Card *card, Player *equiper) {
    listener->onPreLossBlood = std::bind(&Barrel::onPreLossBlood, this, std::placeholders::_1, std::placeholders::_2);
}

bool Barrel::onPreLossBlood(Room *room, Player *loser) {
    if (loser->getEquipment()->isEquipmentCardExist("Barrel")) {
        //        CCard *DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
        //        if (DrawedCard->GetSuit() == Suit::Heart) {
        //            return false;
        //        }
        room->getEventListener()->unsubscribe(listener);
        return true;
    }
    return true;
}
bool Barrel::onUnequip(Room *room, Card *card, Player *unequiper) {
    listener->onPreLossBlood = nullptr;
}