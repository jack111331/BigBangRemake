//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_RETRIEVELOUNGEINFORESPONSE_H
#define BIGBANGREMAKE_RETRIEVELOUNGEINFORESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {
    namespace User {
        struct UserInfo {
            uint32_t id;
            std::string nickname;
            bool ready;
        };
        struct RetrieveLoungeInfoResponse {
            std::vector<UserInfo> memberList;
        };

        void to_json(nlohmann::json &j, const UserInfo &p);

        void from_json(const nlohmann::json &j, UserInfo &p);

        void to_json(nlohmann::json &j, const RetrieveLoungeInfoResponse &p);

        void from_json(const nlohmann::json &j, RetrieveLoungeInfoResponse &p);

    }
}

#endif //BIGBANGREMAKE_RETRIEVELOUNGEINFORESPONSE_H
