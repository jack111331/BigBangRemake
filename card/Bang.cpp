#include "card/Bang.h"
#include <string>
#include <card/Missed.h>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Bang::name = "Bang!";
const string Bang::feature = "Attack one player 1 HP.";

Bang::Bang(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Bang::getName() {
    return Bang::name;
}

const std::string &Bang::getCardName() const {
    return Bang::name;
}

const std::string &Bang::getFeature() {
    return Bang::feature;
}

const std::string &Bang::getCardFeature() const {
    return Bang::feature;
}

bool Bang::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!target->isDead() && room->getDistance(myself, target) <= myself->getAttackRange() && !myself->isAttacked()) {
        room->foldCard(getId(), room->getPositionByPlayer(myself));
        Action::attack(room, myself, target, BangCard::Missed::getName(), &response);
        if (!myself->isHasMultiAttack()) {
            myself->setAttacked(true);
        }
        return true;
    }
    return false;
}

void Bang::handleMessage(const nlohmann::json &jsonMessage) {
    if(jsonMessage.at("resistAttack")) {
        this->response = jsonMessage.at("resistAttack").get<Response::PlayerCard::ResistAttackResponse>();
    }
}
