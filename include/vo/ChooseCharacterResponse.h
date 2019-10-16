//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECHARACTERRESPONSE_H
#define BIGBANGREMAKE_CHOOSECHARACTERRESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {
    namespace Player {
        struct ChooseCharacterResponse {
            std::string chooseCharacterName;
        };

        void to_json(nlohmann::json &j, const ChooseCharacterResponse &p);

        void from_json(const nlohmann::json &j, ChooseCharacterResponse &p);

    }
}

#endif //BIGBANGREMAKE_CHOOSECHARACTERRESPONSE_H
