//
// Created by edge on 2019-10-08.
//

#include "vo/ReadyInLoungeRequest.h"

void Request::User::to_json(nlohmann::json &j, const ReadyInLoungeRequest &p) {
    j = nlohmann::json{{"ready", p.ready}};
}

void Request::User::from_json(const nlohmann::json &j, ReadyInLoungeRequest &p) {
    j.at("ready").get_to(p.ready);
}
