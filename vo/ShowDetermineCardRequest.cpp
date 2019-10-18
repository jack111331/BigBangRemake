//
// Created by edge on 2019-10-08.
//

#include "vo/ShowDetermineCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const ShowDetermineCardRequest &p) {
    j = nlohmann::json{
            {"cardId", p.cardId}
    };
}

void Request::Player::from_json(const nlohmann::json &j, ShowDetermineCardRequest &p) {
    j.at("cardId").get_to(p.cardId);
}
