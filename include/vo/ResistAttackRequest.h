//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_RESISTATTACKREQUEST_H
#define BIGBANGREMAKE_RESISTATTACKREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace PlayerCard {
        struct ResistAttackRequest {
            std::string resistCardName;
        };

        void to_json(nlohmann::json &j, const ResistAttackRequest &p);

        void from_json(const nlohmann::json &j, ResistAttackRequest &p);

    }
}

#endif //BIGBANGREMAKE_RESISTATTACKREQUEST_H
