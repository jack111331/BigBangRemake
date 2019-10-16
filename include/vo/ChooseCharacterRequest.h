//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_CHOOSECHARACTERREQUEST_H
#define BIGBANGREMAKE_CHOOSECHARACTERREQUEST_H

#include <string>
#include "nlohmann/json.hpp"

namespace Request {
    namespace Player {
        struct ChooseCharacterRequest {
            std::vector<std::string> characterNameList;
        };

        void to_json(nlohmann::json &j, const ChooseCharacterRequest &p);

        void from_json(const nlohmann::json &j, ChooseCharacterRequest &p);

    }
}

#endif //BIGBANGREMAKE_CHOOSECHARACTERREQUEST_H
