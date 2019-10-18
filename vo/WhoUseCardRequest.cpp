//WhoUseCardRequest
// Created by edge on 2019-10-08.
//

#include "vo/WhoUseCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const WhoUseCardRequest &p) {
    j = nlohmann::json{
            {"cardId",         p.cardId},
            {"userPosition",   p.userPosition},
            {"targetPosition", p.targetPosition}
    };
}

void Request::Player::from_json(const nlohmann::json &j, WhoUseCardRequest &p) {
    j.at("cardId").get_to(p.cardId);
    j.at("userPosition").get_to(p.userPosition);
    j.at("targetPosition").get_to(p.targetPosition);
}
