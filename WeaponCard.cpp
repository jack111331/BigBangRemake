#include "WeaponCard.h"
#include "Room.h"
#include "Equipment.h"

WeaponCard::WeaponCard(Room *room, int number, Suit suit) : Card(room, number, suit) {

}

bool WeaponCard::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    myself->getEquipment()->setWeaponCard(this);
    room->getEventListener()->notifyEquipEvent(room, this, myself);
    return true;
}
