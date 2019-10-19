//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_INFORMFOLDCARDREQUEST_H
#define BIGBANGREMAKE_INFORMFOLDCARDREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct InformFoldCardRequest {
        };

        void to_json(nlohmann::json &j, const InformFoldCardRequest &p);

        void from_json(const nlohmann::json &j, InformFoldCardRequest &p);

    }
}

#endif //BIGBANGREMAKE_INFORMFOLDCARDREQUEST_H
