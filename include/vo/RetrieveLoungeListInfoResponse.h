//
// Created by edge on 2019-10-08.
//

#ifndef BIGBANGREMAKE_RETRIEVELOUNGELISTINFORESPONSE_H
#define BIGBANGREMAKE_RETRIEVELOUNGELISTINFORESPONSE_H

#include <string>
#include "nlohmann/json.hpp"

namespace Response {
    namespace User {
        struct LoungeInfo {
            uint32_t id;
            size_t memberAmount;
        };
        struct RetrieveLoungeListInfoResponse {
            std::vector<LoungeInfo> loungeList;
        };

        void to_json(nlohmann::json &j, const LoungeInfo &p);

        void from_json(const nlohmann::json &j, LoungeInfo &p);

        void to_json(nlohmann::json &j, const RetrieveLoungeListInfoResponse &p);

        void from_json(const nlohmann::json &j, RetrieveLoungeListInfoResponse &p);

    }
}

#endif //BIGBANGREMAKE_RETRIEVELOUNGELISTINFORESPONSE_H
