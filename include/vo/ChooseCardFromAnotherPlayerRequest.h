//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H
#define BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H

#include <string>
#include "nlohmann/json.hpp"

namespace PlayerCard {
    namespace Request {
        struct ChooseCardFromAnotherPlayerRequest {
            size_t chosenPosition;
            size_t amount;
            std::vector<uint32_t> cardList;
        };

        void to_json(nlohmann::json &j, const ChooseCardFromAnotherPlayerRequest &p);

        void from_json(const nlohmann::json &j, ChooseCardFromAnotherPlayerRequest &p);

    }
}

#endif //BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYER_H
