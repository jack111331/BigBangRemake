//
// Created by edge on 2019-10-08.
//

#include "vo/RetrieveGameInfoRequest.h"

void Request::Player::to_json(nlohmann::json &j, const PlayerInfo &p) {
    j = nlohmann::json{
            {"name", p.name},
            {"position", p.position},
            {"identity", p.identity}
    };
}

void Request::Player::from_json(const nlohmann::json &j, PlayerInfo &p) {
    j.at("name").get_to(p.name);
    j.at("position").get_to(p.position);
    j.at("identity").get_to(p.identity);
}

void Request::Player::to_json(nlohmann::json &j, const CardInfo &p) {
    j = nlohmann::json{
            {"name", p.name},
            {"id", p.id},
            {"suit", p.suit},
            {"number", p.number}
    };
}

void Request::Player::from_json(const nlohmann::json &j, CardInfo &p) {
    j.at("name").get_to(p.name);
    j.at("id").get_to(p.id);
    j.at("suit").get_to(p.suit);
    j.at("number").get_to(p.number);
}

void Request::Player::to_json(nlohmann::json &j, const RetrieveGameInfoRequest &p) {
    j = nlohmann::json{
            {"position", p.position},
            {"identity", p.identity},
            {"playerInfoList", p.playerInfoList},
            {"cardInfoList", p.cardInfoList}
    };
}

void Request::Player::from_json(const nlohmann::json &j, RetrieveGameInfoRequest &p) {
    j.at("position").get_to(p.position);
    j.at("identity").get_to(p.identity);
    j.at("playerInfoList").get_to(p.playerInfoList);
    j.at("cardInfoList").get_to(p.cardInfoList);
}
