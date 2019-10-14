//
// Created by edge on 2019-10-08.
//

#include "vo/ResistAttackRequest.h"

void Request::PlayerCard::to_json(nlohmann::json &j, const ResistAttackRequest &p) {
    j = nlohmann::json{{"resistCardName", p.resistCardName}};
}

void Request::PlayerCard::from_json(const nlohmann::json &j, ResistAttackRequest &p) {
    j.at("resistCardName").get_to(p.resistCardName);
}
