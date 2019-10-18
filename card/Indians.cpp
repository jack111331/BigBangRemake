#include "card/Indians.h"
#include "card/Bang.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Indians::name = "Indians!";
const string Indians::feature = "Every other people should use Bang! to stop attack, or they will loss 1 HP.";

Indians::Indians(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Indians::getName() {
    return Indians::name;
}

const std::string &Indians::getCardName() const {
    return Indians::name;
}

const std::string &Indians::getFeature() {
    return Indians::feature;
}

const std::string &Indians::getCardFeature() const {
    return Indians::feature;
}

bool Indians::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    auto playerList = room->getPlayerList();
    for (auto player : playerList) {
        if (player != myself) {
            Action::attack(room, myself, player, BangCard::Bang::getName(), &response);
            // TODO reset response
        }
    }
    return true;
}

void Indians::handleMessage(const nlohmann::json &jsonMessage) {
    if(jsonMessage.at("resistAttack")) {
        this->response = jsonMessage.at("resistAttack").get<Response::PlayerCard::ResistAttackResponse>();
    }
}
