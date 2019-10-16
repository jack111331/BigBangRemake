//
// Created by edge on 2019-10-08.
//

#include "vo/ChangeNicknameRequest.h"

void Request::User::to_json(nlohmann::json &j, const ChangeNicknameRequest &p) {
    j = nlohmann::json{
            {"nickname", p.nickname}
    };
}

void Request::User::from_json(const nlohmann::json &j, ChangeNicknameRequest &p) {
    j.at("nickname").get_to(p.nickname);
}
