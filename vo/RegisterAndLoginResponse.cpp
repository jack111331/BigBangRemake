//
// Created by edge on 2019-10-08.
//

#include "vo/RegisterAndLoginResponse.h"

void Response::User::to_json(nlohmann::json &j, const RegisterAndLoginResponse &p) {
    j = nlohmann::json{
            {"name", p.name},
            {"win", p.win},
            {"lose", p.lose},
            {"money", p.money}
    };
}

void Response::User::from_json(const nlohmann::json &j, RegisterAndLoginResponse &p) {
    j.at("name").get_to(p.name);
    j.at("win").get_to(p.win);
    j.at("lose").get_to(p.lose);
    j.at("money").get_to(p.money);
}

