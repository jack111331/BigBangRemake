//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_ENDGAMERESPONSE_H
#define BIGBANGREMAKE_ENDGAMERESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {

    namespace Player {
        struct EndGameResponse {
        };
        void to_json(nlohmann::json &j, const EndGameResponse &p);
        void from_json(const nlohmann::json &j, EndGameResponse &p);
    }
}

#endif //BIGBANGREMAKE_ENDGAMERESPONSE_H
