//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECARDFROMCARDLISTRESPONSE_H
#define BIGBANGREMAKE_CHOOSECARDFROMCARDLISTRESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {

    namespace PlayerCard {
        struct ChooseCardFromCardListResponse {
            std::vector<uint32_t> cardList;
        };
        void to_json(nlohmann::json &j, const ChooseCardFromCardListResponse &p);
        void from_json(const nlohmann::json &j, ChooseCardFromCardListResponse &p);
    }
}

#endif //BIGBANGREMAKE_CHOOSECARDFROMANOTHERPLAYERRESPONSE_H
