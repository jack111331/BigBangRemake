//
// Created by edge on 2019-10-08.
//

#include "vo/WhoFoldCardRequest.h"

void Request::Player::to_json(nlohmann::json &j, const WhoFoldCardRequest &p) {
    j = nlohmann::json{
            {"cardId",         p.cardId},
            {"folderPosition", p.folderPosition}
    };
}

void Request::Player::from_json(const nlohmann::json &j, WhoFoldCardRequest &p) {
    j.at("cardId").get_to(p.cardId);
    j.at("folderPosition").get_to(p.folderPosition);
}
