//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_REGISTERANDLOGINRESPONSE_H
#define BIGBANGREMAKE_REGISTERANDLOGINRESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {

    namespace User {
        struct RegisterAndLoginResponse {
            std::string name;
            uint32_t win;
            uint32_t lose;
            int money;
        };
        void to_json(nlohmann::json &j, const RegisterAndLoginResponse &p);
        void from_json(const nlohmann::json &j, RegisterAndLoginResponse &p);
    }
}

#endif //BIGBANGREMAKE_REGISTERANDLOGINRESPONSE_H
