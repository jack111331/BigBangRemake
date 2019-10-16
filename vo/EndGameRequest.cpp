//
// Created by edge on 2019-10-08.
//

#include "vo/EndGameRequest.h"

void Request::Player::to_json(nlohmann::json &j, const EndGameRequest &p) {
    j = nlohmann::json{
            {"win", p.win}
    };
}

void Request::Player::from_json(const nlohmann::json &j, EndGameRequest &p) {
    j.at("win").get_to(p.win);
}
