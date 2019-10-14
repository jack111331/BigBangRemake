//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_ENDGAMEREQUEST_H
#define BIGBANGREMAKE_ENDGAMEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct EndGameRequest {
            bool win;
        };

        void to_json(nlohmann::json &j, const EndGameRequest &p);

        void from_json(const nlohmann::json &j, EndGameRequest &p);

    }
}

#endif //BIGBANGREMAKE_ENDGAMEREQUEST_H
