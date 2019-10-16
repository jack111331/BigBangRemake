//
// Created by edge on 2019-10-08.
//

#include "vo/EndGameResponse.h"

void Response::Player::to_json(nlohmann::json &j, const EndGameResponse &p) {
    j = nlohmann::json{
            {
                    "player",
                    {
                            "endGame", {}
                    }
            }
    };
}

void Response::Player::from_json(const nlohmann::json &j, EndGameResponse &p) {
}

