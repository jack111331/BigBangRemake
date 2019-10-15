//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_JOINLOUNGEREQUEST_H
#define BIGBANGREMAKE_JOINLOUNGEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace User {
        struct JoinLoungeRequest {
            uint32_t loungeId;
        };

        void to_json(nlohmann::json &j, const JoinLoungeRequest &p);

        void from_json(const nlohmann::json &j, JoinLoungeRequest &p);

    }
}

#endif //BIGBANGREMAKE_JOINLOUNGEREQUEST_H
