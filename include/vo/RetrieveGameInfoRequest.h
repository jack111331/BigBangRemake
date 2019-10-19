//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_RETRIEVEGAMEINFOREQUEST_H
#define BIGBANGREMAKE_RETRIEVEGAMEINFOREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct PlayerInfo {
            std::string name;
            size_t position;
            std::string identity;
        };
        struct CardInfo {
            std::string name;
            uint32_t id;
            std::string suit;
            int number;
        };

        struct RetrieveGameInfoRequest {
            size_t position;
            std::string identity;
            std::vector<PlayerInfo> playerInfoList;
            std::vector<CardInfo> cardInfoList;
        };
        void to_json(nlohmann::json &j, const PlayerInfo &p);

        void from_json(const nlohmann::json &j, PlayerInfo &p);

        void to_json(nlohmann::json &j, const CardInfo &p);

        void from_json(const nlohmann::json &j, CardInfo &p);

        void to_json(nlohmann::json &j, const RetrieveGameInfoRequest &p);

        void from_json(const nlohmann::json &j, RetrieveGameInfoRequest &p);

    }
}

#endif //BIGBANGREMAKE_RETRIEVEGAMEINFOREQUEST_H
