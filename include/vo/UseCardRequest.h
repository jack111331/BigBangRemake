//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_USECARDREQUEST_H
#define BIGBANGREMAKE_USECARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        const uint32_t NO_TARGET = 0xffffffff;
        struct UseCardRequest {
            uint32_t cardId;
            uint32_t targetPosition;
        };

        void to_json(nlohmann::json &j, const UseCardRequest &p);

        void from_json(const nlohmann::json &j, UseCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_USECARDREQUEST_H
