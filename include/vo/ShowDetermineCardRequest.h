//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_SHOWDETERMINECARDREQUEST_H
#define BIGBANGREMAKE_SHOWDETERMINECARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct ShowDetermineCardRequest {
            uint32_t cardId;
        };

        void to_json(nlohmann::json &j, const ShowDetermineCardRequest &p);

        void from_json(const nlohmann::json &j, ShowDetermineCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_SHOWDETERMINECARDREQUEST_H
