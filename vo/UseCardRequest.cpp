//
// Created by edge on 2019-10-08.
//

#include "vo/UseCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const UseCardRequest &p) {
    j = nlohmann::json{
            {"cardId",         p.cardId},
            {"targetPosition", p.targetPosition}
    };
}

void Request::Player::from_json(const nlohmann::json &j, UseCardRequest &p) {
    j.at("cardId").get_to(p.cardId);
    j.at("targetPosition").get_to(p.targetPosition);
}
