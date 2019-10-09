//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H
#define BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H

#include <string>
#include "nlohmann/json.hpp"

namespace PlayerCard {

    namespace Response {
        struct ChooseCardFromAnotherPlayerResponse {
            std::vector<uint32_t> cardList;
        };
        void to_json(nlohmann::json &j, const ChooseCardFromAnotherPlayerResponse &p);
        void from_json(const nlohmann::json &j, ChooseCardFromAnotherPlayerResponse &p);
    }
}

#endif //BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H
