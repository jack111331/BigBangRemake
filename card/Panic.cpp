#include "card/Panic.h"
#include <string>
#include <Network.h>
#include <vo/ChooseCardFromCardListRequest.h>
#include "Room.h"
#include "Action.h"
//#include "DrawCardFactory.h"


using std::string;
using namespace BangCard;

const string Panic::name = "Panic!";
const string Panic::feature = "Choose one card of one player whose distance between you under 1.";

Panic::Panic(Room *room, int number, Suit suit) : Card(room, number, suit) {
}


const std::string &Panic::getName() {
    return Panic::name;
}

const std::string &Panic::getCardName() const {
    return Panic::name;
}

const std::string &Panic::getFeature() {
    return Panic::feature;
}

const std::string &Panic::getCardFeature() const {
    return Panic::feature;
}

bool Panic::useCardEffect(Room *room, Player *myself, Player *target) {
    if (room->getDistance(myself, target) <= 1) {
        if (!Card::useCardEffect(room, myself, target)) {
            return false;
        }
        auto network = Network::getInstance();
        auto targetHoldingList = target->getHolding();
        Request::PlayerCard::ChooseCardFromCardListRequest request;
        request.amount = targetHoldingList.size();
        for(auto holding : targetHoldingList) {
            request.cardList.push_back(holding->getId());
        }
        network->sendMessage(myself->getAgent()->getToken(), nlohmann::json(request).dump());
        std::unique_lock<std::mutex> lock(conditionVariableMutex);
        conditionVariable.wait(lock, [this] { return response.cardList.size(); });
        for(auto card : response.cardList) {
            room->giveCard(card, room->getPositionByPlayer(target), room->getPositionByPlayer(myself));
        }
        return true;
    }
    return false;
}

void Panic::handleMessage(const nlohmann::json &jsonMessage) {
    if(jsonMessage.at("chooseCardFromAnotherPlayer")) {
        this->response = jsonMessage.at("chooseCardFromAnotherPlayer").get<Response::PlayerCard::ChooseCardFromAnotherPlayerResponse>();
    }
}
