//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_INFORMUSECARDREQUEST_H
#define BIGBANGREMAKE_INFORMUSECARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct InformUseCardRequest {
        };

        void to_json(nlohmann::json &j, const InformUseCardRequest &p);

        void from_json(const nlohmann::json &j, InformUseCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_INFORMUSECARDREQUEST_H
