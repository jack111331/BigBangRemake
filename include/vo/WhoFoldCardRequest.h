//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_WHOFOLDCARDREQUEST_H
#define BIGBANGREMAKE_WHOFOLDCARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct WhoFoldCardRequest {
            uint32_t cardId;
            size_t folderPosition;
        };

        void to_json(nlohmann::json &j, const WhoFoldCardRequest &p);

        void from_json(const nlohmann::json &j, WhoFoldCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_WHOFOLDCARDREQUEST_H
