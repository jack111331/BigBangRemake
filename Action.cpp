#include <Network.h>
#include <vo/ResistAttackRequest.h>
#include "Action.h"
#include "Player.h"
#include "Plague.h"
#include "GameEventListener.h"
#include "Room.h"

bool Action::attack(Room *room, Player *attacker, Player *attackee, const std::string &dodgeByCardName,
                    Response::PlayerCard::ResistAttackResponse *response) {
    std::condition_variable conditionVariable;
    std::mutex conditionVariableMutex;
    auto network = Network::getInstance();
    Card *resistCard = attackee->getCardInHoldingByName(dodgeByCardName);
    if (resistCard) {
        // Invoke player to choose whether he want to use this card
        Request::PlayerCard::ResistAttackRequest request = {dodgeByCardName};
        network->sendMessage(attackee->getAgent()->getToken(), nlohmann::json(request).dump());
        std::unique_lock<std::mutex> lock(conditionVariableMutex);
        conditionVariable.wait(lock, [response] { return response->updated; });
        int resist = response->resist;
        if (resist) {
            room->foldCard(resistCard->getId(), room->getPositionByPlayer(attackee));
            return false;
        } else {
            lossHealth(room, attackee, attacker, 1);
            return true;
        }
    } else {
        lossHealth(room, attackee, attacker, 1);
        return true;
    }
}

void Action::lossHealth(Room *room, Player *target, Player *attacker, int health) {
    room->getEventListener()->notifyPreLossBloodEvent(room, target);
    target->setHp(target->getHp() - health);
    room->getEventListener()->notifyLossBloodEvent(room, target, attacker);
    if (target->getHp() <= 0) {
        room->getEventListener()->notifyDeathEvent(room, target, attacker);
        if (target->getHp() <= 0) {
            target->setDead(true);
        }
    }
}

void Action::recoverHealth(Player *target, int health) {
    target->setHp(std::min(target->getHp() + health, target->getMaxHp()));
}
