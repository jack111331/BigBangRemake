//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_WHOUSECARDREQUEST_H
#define BIGBANGREMAKE_WHOUSECARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct WhoUseCardRequest {
            uint32_t cardId;
            size_t userPosition;
            size_t targetPosition;
        };

        void to_json(nlohmann::json &j, const WhoUseCardRequest &p);

        void from_json(const nlohmann::json &j, WhoUseCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_WHOUSECARDREQUEST_H
