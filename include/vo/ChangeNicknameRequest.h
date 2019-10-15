//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHANGENICKNAMEREQUEST_H
#define BIGBANGREMAKE_CHANGENICKNAMEREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace User {
        struct ChangeNicknameRequest {
            std::string nickname;
        };

        void to_json(nlohmann::json &j, const ChangeNicknameRequest &p);

        void from_json(const nlohmann::json &j, ChangeNicknameRequest &p);

    }
}

#endif //BIGBANGREMAKE_CHANGENICKNAMEREQUEST_H
