//
// Created by edge on 2019-10-08.
//

#include "vo/ChooseCardFromCardListResponse.h"

void Response::PlayerCard::to_json(nlohmann::json &j, const ChooseCardFromCardListResponse &p) {
    j = nlohmann::json{
            {"cardList", p.cardList}
    };
}

void Response::PlayerCard::from_json(const nlohmann::json &j, ChooseCardFromCardListResponse &p) {
    j.at("cardList").get_to(p.cardList);
}

