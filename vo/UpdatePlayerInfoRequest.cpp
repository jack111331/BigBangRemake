//
// Created by edge on 2019-10-08.
//

#include "vo/UpdatePlayerInfoRequest.h"

void Request::Player::to_json(nlohmann::json &j, const UpdatePlayerInfoRequest &p) {
    j = nlohmann::json{
            {"identity", p.identity},
            {"character", p.character},
//            {"equipmentList", p.equipmentList},
            {"hp", p.hp},
            {"holdingAmount", p.holdingAmount},
            {"dead", p.dead}
    };
}

void Request::Player::from_json(const nlohmann::json &j, UpdatePlayerInfoRequest &p) {
    j.at("identity").get_to(p.identity);
    j.at("character").get_to(p.character);
//    j.at("equipmentList").get_to(p.equipmentList);
    j.at("hp").get_to(p.hp);
    j.at("holdingAmount").get_to(p.holdingAmount);
    j.at("dead").get_to(p.dead);
}
