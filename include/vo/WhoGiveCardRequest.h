//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_WHOGIVECARDREQUEST_H
#define BIGBANGREMAKE_WHOGIVECARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct WhoGiveCardRequest {
            uint32_t cardId;
            size_t giverPosition;
            size_t receiverPosition;
        };

        void to_json(nlohmann::json &j, const WhoGiveCardRequest &p);

        void from_json(const nlohmann::json &j, WhoGiveCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_WHOGIVECARDREQUEST_H
