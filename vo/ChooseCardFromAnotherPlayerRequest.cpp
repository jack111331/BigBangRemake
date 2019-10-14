//
// Created by edge on 2019-10-08.
//

#include "vo/ChooseCardFromAnotherPlayerRequest.h"

void Request::PlayerCard::to_json(nlohmann::json &j, const ChooseCardFromAnotherPlayerRequest &p) {
    j = nlohmann::json{{"chosenPosition", p.chosenPosition},
                       {"amount",         p.amount},
                       {"cardList",       p.cardList}};
}

void Request::PlayerCard::from_json(const nlohmann::json &j, ChooseCardFromAnotherPlayerRequest &p) {
    j.at("chosenPosition").get_to(p.chosenPosition);
    j.at("amount").get_to(p.amount);
    j.at("cardList").get_to(p.cardList);
}
