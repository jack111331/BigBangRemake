//
// Created by edge on 2019-10-08.
//

#include "vo/FoldCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const FoldCardRequest &p) {
    j = nlohmann::json{
            {"amount", p.amount}
    };
}

void Request::Player::from_json(const nlohmann::json &j, FoldCardRequest &p) {
    j.at("amount").get_to(p.amount);
}
