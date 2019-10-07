#include "card/Dynamite.h"
#include <string>
#include "Room.h"
#include "Action.h"

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
    listener->onDrawCard = std::bind(&Dynamite::onDrawCard, this, std::placeholders::_1, std::placeholders::_2);
}

bool Dynamite::onUnequip(Room *room, Card *card, Player *unequiper) {
    listener->onDrawCard = nullptr;
}

bool Dynamite::onDrawCard(Room *room, Player *drawer) {
    //    if (drawer->GetEquipment() && drawer->GetEquipment()->GetName() == "Dynamite") {
    //        CCard *DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
    //        if (DrawedCard->GetSuit() == Suit::Spade && DrawedCard->GetNumber() >= 2 && DrawedCard->GetNumber() <= 9) {
    //            drawer->SetHP(drawer->GetHP() - 3);
    //            if (drawer->GetHP() <= 0) {
    //                room->GetRoomEvent()->callDeath(room, drawer, drawer);
    //                if (drawer->GetHP() <= 0) {
    //                    drawer->SetDead(true);
    //                }
    //            }
    //        } else {
    //            CPlayer *NextPlayer = room->GetNextPlayer(drawer);
    //            NextPlayer->AddHolding(const_cast<CCard *>(drawer->GetEquipment()));
    //            NextPlayer->UseCard(room, NextPlayer->GetCardInHolding("Dynamite")->GetID(), nullptr);//equip immediately
    //        }
    //        room->GetDiscardPlague()->InsertCardToPlague(DrawedCard);
    //        drawer->ChangeEquipment(nullptr);
    //    }
    return true;
}
