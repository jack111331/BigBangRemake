//
// Created by edge on 2019-10-08.
//

#include "vo/WhoGiveCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const WhoGiveCardRequest &p) {
    j = nlohmann::json{
            {"cardId",           p.cardId},
            {"giverPosition",    p.giverPosition},
            {"receiverPosition", p.receiverPosition}
    };
}

void Request::Player::from_json(const nlohmann::json &j, WhoGiveCardRequest &p) {
    j.at("cardId").get_to(p.cardId);
    j.at("giverPosition").get_to(p.giverPosition);
    j.at("receiverPosition").get_to(p.receiverPosition);
}
