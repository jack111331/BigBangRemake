//
// Created by edge on 2019-10-08.
//

#include "vo/ChooseCardFromAnotherPlayerResponse.h"

void PlayerCard::Response::to_json(nlohmann::json &j, const ChooseCardFromAnotherPlayerResponse &p) {
    j = nlohmann::json{{"cardList", p.cardList}};
}

void PlayerCard::Response::from_json(const nlohmann::json &j, ChooseCardFromAnotherPlayerResponse &p) {
    j.at("cardList").get_to(p.cardList);
}

