//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_STARTLOUNGEGAMERESPONSE_H
#define BIGBANGREMAKE_STARTLOUNGEGAMERESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {

    namespace User {
        struct StartLoungeGameResponse {
        };
        void to_json(nlohmann::json &j, const StartLoungeGameResponse &p);
        void from_json(const nlohmann::json &j, StartLoungeGameResponse &p);
    }
}

#endif //BIGBANGREMAKE_STARTLOUNGEGAMERESPONSE_H
