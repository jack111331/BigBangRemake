#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventListener.h"
#include "Room.h"

bool Action::attack(Room *room, Player *attacker, Player *attackee, std::string dodgeByCardName) {
    //TODO
    Card *HoldingRevoltCard = attackee->getCardInHoldingByName(dodgeByCardName);
    if (HoldingRevoltCard != nullptr) {
        if (!room->getEventListener()->notifyPreLossBloodEvent(room, attackee)) {
            return false;
        }
        //invoke player to choose whether he want to use this card
//        attackee->getAgent()->SendMessage("Send Message", NSWrapInfo::WrapRevoltCard(HoldingRevoltCard).dump());
//        int Revolt = attackee->BusyWaiting(12);
//        printf("Revolt: %d\n", Revolt);
//        if (Revolt) {
//            attackee->removeCardInHolding(HoldingRevoltCard);
//            return false;
//        } else {
//            room->getEventListener()->notifyLossBloodEvent(room, attackee, attacker);
//            attackee->setHp(attackee->getHp() - 1);
//            if (attackee->getHp() <= 0) {
//                room->getEventListener()->notifyDeathEvent(room, attackee, attacker);
//                if (attackee->getHp() <= 0) {
//                    attackee->setDead(true);
//                }
//            }
//            return true;
//        }
    } else {
        room->getEventListener()->notifyLossBloodEvent(room, attackee, attacker);
        attackee->setHp(attackee->getHp() - 1);
        if (attackee->getHp() <= 0) {
            room->getEventListener()->notifyDeathEvent(room, attackee, attacker);
            if (attackee->getHp() <= 0) {
                attackee->setDead(true);
            }
        }
        return true;
    }
}

void Action::recoverHealth(Player *target, int health) {
    target->setHp(std::min(target->getHp() + health, target->getMaxHp()));
}
