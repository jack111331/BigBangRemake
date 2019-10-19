//
// Created by edge on 2019-10-18.
//

#ifndef BIGBANGREMAKE_USERSERVICE_H
#define BIGBANGREMAKE_USERSERVICE_H


#include <nlohmann/json.hpp>
#include "Network.h"

class Lounge;

class UserService {
public:
    UserService();

    template<typename T>
    nlohmann::json packAsJson(std::string requestName, T request);

    void sendRetrieveLoungeListInfoResponse(User *sendToUser, const std::vector<Lounge *> &loungeList);

    void sendRetrieveLoungeInfoResponse(User *sendToUser, Lounge * lounge);

    void sendStartLoungeGameResponse(const std::vector<User *> &sendToUserList);

private:
    Network *network;
};


#endif //BIGBANGREMAKE_USERSERVICE_H
