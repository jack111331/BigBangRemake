#include "card/Jail.h"
#include <string>
#include "Room.h"
#include "User.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Jail::name = "Jail";
const string Jail::feature = "When equipped, draw card and determine if the drawed card is heart, then jail will be Unequiped, otherwise player will be deprived draw card right.";

Jail::Jail(Room *room, int number, Suit suit) : EquipmentCard(room, number, suit) {
    this->listener = new GameEventListener();
    listener->onEquip = std::bind(&Jail::onEquip, this, std::placeholders::_1, std::placeholders::_2,
                                  std::placeholders::_3);
    listener->onUnequip = std::bind(&Jail::onUnequip, this, std::placeholders::_1, std::placeholders::_2,
                                    std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &Jail::getName() {
    return Jail::name;
}

const std::string &Jail::getCardName() const {
    return Jail::name;
}

const std::string &Jail::getFeature() {
    return Jail::feature;
}

const std::string &Jail::getCardFeature() const {
    return Jail::feature;
}

bool Jail::useCardEffect(Room *room, Player *myself, Player *target) {
    // TODO Pre draw card
    if (target->getIdentity() != Team::Sergeant) {
        if(!EquipmentCard::useCardEffect(room, myself, target)) {
            return false;
        }
//        GetInRoom()->GetRoomEvent()->callEquip(this, target);
        return true;
    }
    return false;
}

bool Jail::onEquip(Room *room, Card *card, Player *equiper) {
    listener->onPreDrawCard = std::bind(&Jail::onPreDrawCard, this, std::placeholders::_1, std::placeholders::_2);
}

bool Jail::onUnequip(Room *room, Card *card, Player *unequiper) {
    listener->onPreDrawCard = nullptr;
}

bool Jail::onPreDrawCard(Room *room, Player *drawer) {
    // TODO refactor this
//    if (drawer->GetEquipment() && drawer->GetEquipment()->GetName() == "Jail") {
//        CCard *DrawedCard = NSAction::DrawCardFromPlagueForDetermine(room);
//        room->GetDiscardPlague()->InsertCardToPlague(DrawedCard);
//        drawer->ChangeEquipment(nullptr);
//        if (DrawedCard->GetSuit() != Suit::Heart) {
//            drawer->GetUser()->SendMessage("Handled Data", std::to_string(13));
//            return false;
//        }
//    }
    return true;
}

Jail::~Jail() {
    delete listener;
}