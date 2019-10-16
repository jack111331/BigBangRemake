//
// Created by edge on 2019-10-08.
//

#include "vo/ChooseCharacterRequest.h"

void Request::Player::to_json(nlohmann::json &j, const ChooseCharacterRequest &p) {
    j = nlohmann::json{
            {"characterNameList", p.characterNameList}
    };
}

void Request::Player::from_json(const nlohmann::json &j, ChooseCharacterRequest &p) {
    j.at("characterNameList").get_to(p.characterNameList);
}
