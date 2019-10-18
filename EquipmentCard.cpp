#include "EquipmentCard.h"
//#include "GameEventObserver.h"
#include "Room.h"
#include "Action.h"

EquipmentCard::EquipmentCard(Room *room, int number, Suit suit) : Card(room, number, suit) {

}

bool EquipmentCard::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    room->getEventListener()->notifyEquipEvent(room, this, myself);
    return true;
}
