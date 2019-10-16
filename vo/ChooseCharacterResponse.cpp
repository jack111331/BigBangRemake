//    j.at("targetPosition").get_to(p.targetPosition);

// Created by edge on 2019-10-08.
//

#include "vo/ChooseCharacterResponse.h"

void Response::Player::to_json(nlohmann::json &j, const ChooseCharacterResponse &p) {
    j = nlohmann::json{
            {"chooseCharacterName", p.chooseCharacterName}
    };
}

void Response::Player::from_json(const nlohmann::json &j, ChooseCharacterResponse &p) {
    j.at("chooseCharacterName").get_to(p.chooseCharacterName);
}
