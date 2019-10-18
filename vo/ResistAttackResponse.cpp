//
// Created by edge on 2019-10-08.
//

#include "vo/ResistAttackResponse.h"

void Response::PlayerCard::to_json(nlohmann::json &j, const ResistAttackResponse &p) {
    j = nlohmann::json{
            {"resist", p.resist}
    };
}

void Response::PlayerCard::from_json(const nlohmann::json &j, ResistAttackResponse &p) {
    p.updated = true;
    j.at("resist").get_to(p.resist);
}

