//
// Created by edge on 2019-10-08.
//

#include "vo/RetrieveLoungeListInfoResponse.h"

void Response::User::to_json(nlohmann::json &j, const LoungeInfo &p) {
    j = nlohmann::json{{"id",           p.id},
                       {"memberAmount", p.memberAmount}};
}

void Response::User::from_json(const nlohmann::json &j, LoungeInfo &p) {
    j.at("id").get_to(p.id);
    j.at("memberAmount").get_to(p.memberAmount);
}

void Response::User::to_json(nlohmann::json &j, const RetrieveLoungeListInfoResponse &p) {
    j = nlohmann::json{{"loungeList", p.loungeList}};
}

void Response::User::from_json(const nlohmann::json &j, RetrieveLoungeListInfoResponse &p) {
    j.at("loungeList").get_to(p.loungeList);
}
