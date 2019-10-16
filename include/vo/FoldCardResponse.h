//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_FOLDCARDRESPONSE_H
#define BIGBANGREMAKE_FOLDCARDRESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {
    namespace Player {
        const uint32_t NO_TARGET = 0xffffffff;
        struct FoldCardResponse {
            std::vector<uint32_t> cardIdList;
        };

        void to_json(nlohmann::json &j, const FoldCardResponse &p);

        void from_json(const nlohmann::json &j, FoldCardResponse &p);

    }
}

#endif //BIGBANGREMAKE_FOLDCARDRESPONSE_H
