//
// Created by edge on 2019-10-08.
//

#include "vo/JoinLoungeRequest.h"

void Request::User::to_json(nlohmann::json &j, const JoinLoungeRequest &p) {
    j = nlohmann::json{
            {"loungeId", p.loungeId}
    };
}

void Request::User::from_json(const nlohmann::json &j, JoinLoungeRequest &p) {
    j.at("loungeId").get_to(p.loungeId);
}
