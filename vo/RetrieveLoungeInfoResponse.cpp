//
// Created by edge on 2019-10-08.
//

#include "vo/RetrieveLoungeInfoResponse.h"

void Response::User::to_json(nlohmann::json &j, const UserInfo &p) {
    j = nlohmann::json{
            {"id",       p.id},
            {"nickname", p.nickname},
            {"ready",    p.ready}
    };
}

void Response::User::from_json(const nlohmann::json &j, UserInfo &p) {
    j.at("id").get_to(p.id);
    j.at("nickname").get_to(p.nickname);
    j.at("ready").get_to(p.ready);
}

void Response::User::to_json(nlohmann::json &j, const RetrieveLoungeInfoResponse &p) {
    j = nlohmann::json{{"memberList", p.memberList}};
}

void Response::User::from_json(const nlohmann::json &j, RetrieveLoungeInfoResponse &p) {
    j.at("memberList").get_to(p.memberList);
}
