//
// Created by edge on 2019-10-08.
//

#include "vo/ChooseCardFromCardListRequest.h"

void Request::PlayerCard::to_json(nlohmann::json &j, const ChooseCardFromCardListRequest &p) {
    j = nlohmann::json{
            {"amount",   p.amount},
            {"cardList", p.cardList}
    };
}

void Request::PlayerCard::from_json(const nlohmann::json &j, ChooseCardFromCardListRequest &p) {
    j.at("amount").get_to(p.amount);
    j.at("cardList").get_to(p.cardList);
}
