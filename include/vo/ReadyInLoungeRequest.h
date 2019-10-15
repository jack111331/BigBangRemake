//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_READYINLOUNGEREQUEST_H
#define BIGBANGREMAKE_READYINLOUNGEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace User {
        struct ReadyInLoungeRequest {
            bool ready;
        };

        void to_json(nlohmann::json &j, const ReadyInLoungeRequest &p);

        void from_json(const nlohmann::json &j, ReadyInLoungeRequest &p);

    }
}

#endif //BIGBANGREMAKE_READYINLOUNGEREQUEST_H
