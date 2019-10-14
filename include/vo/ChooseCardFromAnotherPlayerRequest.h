//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYERREQUEST_H
#define BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYERREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace PlayerCard {
        struct ChooseCardFromAnotherPlayerRequest {
            size_t chosenPosition;
            size_t amount;
            std::vector<uint32_t> cardList;
        };

        void to_json(nlohmann::json &j, const ChooseCardFromAnotherPlayerRequest &p);

        void from_json(const nlohmann::json &j, ChooseCardFromAnotherPlayerRequest &p);

    }
}

#endif //BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYERREQUEST_H
