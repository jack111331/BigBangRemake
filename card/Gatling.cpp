#include "card/Gatling.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Gatling::name = "Gatling";
const string Gatling::feature = "Every other people should use Missed! to stop attack, or they will loss 1 HP.";


Gatling::Gatling(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Gatling::getName() {
    return Gatling::name;
}

const std::string &Gatling::getCardName() const {
    return Gatling::name;
}

const std::string &Gatling::getFeature() {
    return Gatling::feature;
}

const std::string &Gatling::getCardFeature() const {
    return Gatling::feature;
}

bool Gatling::useCardEffect(Room *room, Player *myself, Player *target) {
    if(!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    auto playerList = room->getPlayerList();
    for (auto player : playerList) {
        if (player != myself) {
            Action::attack(room, myself, player, BangCard::Gatling::getName(), &response);
            response.updated = false;
        }
    }
    return true;
}

void Gatling::handleMessage(const nlohmann::json &jsonMessage) {
    if(jsonMessage.at("resistAttack")) {
        this->response = jsonMessage.at("resistAttack").get<Response::PlayerCard::ResistAttackResponse>();
    }
}
