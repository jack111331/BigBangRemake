//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECARDFROMCARDLISTREQUEST_H
#define BIGBANGREMAKE_CHOOSECARDFROMCARDLISTREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace PlayerCard {
        struct ChooseCardFromCardListRequest {
            size_t amount;
            std::vector<uint32_t> cardList;
        };

        void to_json(nlohmann::json &j, const ChooseCardFromCardListRequest &p);

        void from_json(const nlohmann::json &j, ChooseCardFromCardListRequest &p);

    }
}

#endif //BIGBANGREMAKE_CHOOSECARDFROMCARDLISTREQUEST_H
