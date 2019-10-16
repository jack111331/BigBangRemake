//
// Created by edge on 2019-10-08.
//

#include "vo/FoldCardResponse.h"

void Response::Player::to_json(nlohmann::json &j, const FoldCardResponse &p) {
    j = nlohmann::json{
            {"cardIdList", p.cardIdList}
    };
}

void Response::Player::from_json(const nlohmann::json &j, FoldCardResponse &p) {
    j.at("cardIdList").get_to(p.cardIdList);
}
