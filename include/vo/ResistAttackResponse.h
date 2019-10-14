//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_RESISTATTACKRESPONSE_H
#define BIGBANGREMAKE_RESISTATTACKRESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {

    namespace PlayerCard {
        struct ResistAttackResponse {
            bool resist;
        };
        void to_json(nlohmann::json &j, const ResistAttackResponse &p);
        void from_json(const nlohmann::json &j, ResistAttackResponse &p);
    }
}

#endif //BIGBANGREMAKE_RESISTATTACKRESPONSE_H
