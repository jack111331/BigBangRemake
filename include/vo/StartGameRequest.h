//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_STARTGAMEREQUEST_H
#define BIGBANGREMAKE_STARTGAMEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace PlayerCard {
        struct StartGameRequest {
        };

        void to_json(nlohmann::json &j, const StartGameRequest &p);

        void from_json(const nlohmann::json &j, StartGameRequest &p);

    }
}

#endif //BIGBANGREMAKE_STARTGAMEREQUEST_H
