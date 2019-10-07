#include "WeaponCard.h"
//#include "GameEventObserver.h"
#include "Room.h"
#include "Action.h"

WeaponCard::WeaponCard(Room *room, int number, Suit suit) : EquipmentCard(room, number, suit) {

}

bool WeaponCard::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!EquipmentCard::useCardEffect(room, myself, target)) {
        return false;
    }
    //    GetInRoom()->GetRoomEvent()->callEquip(this, myself);
    return true;
}
