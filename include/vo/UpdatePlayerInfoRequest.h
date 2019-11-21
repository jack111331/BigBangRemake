//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_UPDATEPLAYERINFOREQUEST_H
#define BIGBANGREMAKE_UPDATEPLAYERINFOREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct UpdatePlayerInfoRequest {
            std::string identity;
            std::string character;
//            std::vector<uint32_t> equipmentList;
            int hp;
            size_t holdingAmount;
            bool dead;
        };

        void to_json(nlohmann::json &j, const UpdatePlayerInfoRequest &p);

        void from_json(const nlohmann::json &j, UpdatePlayerInfoRequest &p);

    }
}

#endif //BIGBANGREMAKE_UPDATEPLAYERINFOREQUEST_H
