#include "card/CatBalou.h"
#include <string>
#include "Room.h"
#include "User.h"


using std::string;
using namespace BangCard;

const string CatBalou::name = "Cat Balou";
const string CatBalou::feature = "Discard one card from one player.";


CatBalou::CatBalou(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &CatBalou::getName() {
    return CatBalou::name;
}

const std::string &CatBalou::getCardName() const {
    return CatBalou::name;
}

const std::string &CatBalou::getFeature() {
    return CatBalou::feature;
}

const std::string &CatBalou::getCardFeature() const {
    return CatBalou::feature;
}

bool CatBalou::useCardEffect(Room *room, Player *myself, Player *target) {
    if(!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    // TODO fix communicate
//    myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
//    target->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
//    myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCard(myself, target, false).dump());
    std::unique_lock<std::mutex> lock(conditionVariableMutex);
    conditionVariable.wait(lock, [this]{return response.cardList.size();});
    for(auto card : response.cardList) {
        room->foldCard(card, room->getPositionByPlayer(target));
    }
    return true;
}

void CatBalou::handleMessage(const nlohmann::json &jsonMessage) {
    if(jsonMessage.at("chooseCardFromAnotherPlayer")) {
        this->response = jsonMessage.at("chooseCardFromAnotherPlayer").get<Response::PlayerCard::ChooseCardFromAnotherPlayerResponse>();
    }
}

