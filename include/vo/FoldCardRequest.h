//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_FOLDCARDREQUEST_H
#define BIGBANGREMAKE_FOLDCARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        const uint32_t NO_TARGET = 0xffffffff;
        struct FoldCardRequest {
            uint32_t amount;
        };

        void to_json(nlohmann::json &j, const FoldCardRequest &p);

        void from_json(const nlohmann::json &j, FoldCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_FOLDCARDREQUEST_H
