#include "card/GeneralStore.h"
#include <string>
#include "Room.h"
#include <vector>
#include <Network.h>
#include <vo/ChooseCardFromCardListRequest.h>
#include <Logger.h>
#include "User.h"

using std::string;
using namespace BangCard;

const string GeneralStore::name = "General Store";
const string GeneralStore::feature = "Draw alive amount player card and distribute them to every player, start from yourself.";

GeneralStore::GeneralStore(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &GeneralStore::getName() {
    return GeneralStore::name;
}

const std::string &GeneralStore::getCardName() const {
    return GeneralStore::name;
}

const std::string &GeneralStore::getFeature() {
    return GeneralStore::feature;
}

const std::string &GeneralStore::getCardFeature() const {
    return GeneralStore::feature;
}

bool GeneralStore::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    auto network = Network::getInstance();
    size_t drawCardAmount = room->getAlivePlayerAmount();
    std::map<uint32_t, Card *> chooseCardSet;
    for (size_t i = 0; i < drawCardAmount; i++) {
        auto card = room->drawCardFromPlagueForDetermine();
        chooseCardSet.insert(std::pair<uint32_t, Card *>(card->getId(), card));
    }
    for (Player *currentPlayer = myself;
         room->getNextPlayer(currentPlayer) != myself; currentPlayer = room->getNextPlayer(currentPlayer)) {
        Request::PlayerCard::ChooseCardFromCardListRequest request;
        request.amount = 1;
        for (auto card : chooseCardSet) {
            request.cardList.push_back(card.first);
        }
        network->sendMessage(currentPlayer->getAgent()->getToken(), nlohmann::json(request).dump());
        std::unique_lock<std::mutex> lock(conditionVariableMutex);
        conditionVariable.wait(lock, [this] { return response.cardList.size(); });
        for (auto card : response.cardList) {
            if (chooseCardSet.find(card) != chooseCardSet.end()) {
                currentPlayer->addCardToHolding(chooseCardSet.at(card));
                chooseCardSet.erase(card);
            } else {
                auto logger = Logger::getLogger("[Card]");
                logger->error("Wrong Card, card={}", card);
            }
        }
        response.cardList.clear();
    }
    return true;
}

void GeneralStore::handleMessage(const nlohmann::json &jsonMessage) {
    if (jsonMessage.at("chooseCardFromCardList")) {
        this->response = jsonMessage.at(
                "chooseCardFromCardList").get<Response::PlayerCard::ChooseCardFromCardListResponse>();
    }
}
