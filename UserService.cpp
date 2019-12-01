//
// Created by edge on 2019-10-18.
//

#include <vo/RegisterAndLoginResponse.h>
#include <vo/StartLoungeGameResponse.h>
#include <vo/RetrieveLoungeListInfoResponse.h>
#include <vo/RetrieveLoungeInfoResponse.h>
#include <Lounge.h>
#include "UserService.h"
#include "User.h"

using nlohmann::json;

UserService::UserService() {
    this->network = Network::getInstance();
}

template<typename T>
json UserService::packAsJson(std::string requestName, T request) {
    json functionRequest;
    functionRequest[requestName] = request;
    json completeRequest;
    completeRequest["user"] = functionRequest;
    return completeRequest;
}

void UserService::sendRegisterAndLoginResponse(User *sendToUser,
                                                     User *user) {
    Response::User::RegisterAndLoginResponse response;
    response.name = user->getName();
    response.win = user->getWin();
    response.lose = user->getLose();
    response.money = user->getMoney();
    json registerAndLoginResponse = packAsJson("registerAndLogin", response);
    network->sendMessage(sendToUser->getAgent()->getToken(), json(registerAndLoginResponse).dump());
}

void UserService::sendRetrieveLoungeListInfoResponse(User *sendToUser,
                                                     const std::vector<Lounge *> &loungeList) {
    Response::User::RetrieveLoungeListInfoResponse response;
    for (const auto lounge : loungeList) {
        response.loungeList.push_back({lounge->getId(), lounge->getLoungeSize()});
    }
    json retrieveLoungeListInfoResponse = packAsJson("retrieveLoungeListInfo", response);
    network->sendMessage(sendToUser->getAgent()->getToken(), json(retrieveLoungeListInfoResponse).dump());
}

void UserService::sendRetrieveLoungeInfoResponse(User *sendToUser, Lounge * lounge) {
    Response::User::RetrieveLoungeInfoResponse response;
    auto userList = lounge->getUserList();
    for (const auto user : userList) {
        response.memberList.push_back({user->getId(), user->getName(), lounge->getReadyState(user)});
    }
    json retrieveLoungeInfoResponse = packAsJson("retrieveLoungeInfo", response);
    network->sendMessage(sendToUser->getAgent()->getToken(), json(retrieveLoungeInfoResponse).dump());
}

void UserService::sendStartLoungeGameResponse(const std::vector<User *> &sendToUserList) {
    Response::User::StartLoungeGameResponse response = {};
    json startLoungeGameResponse = packAsJson("startLoungeGame", response);
    for (auto user : sendToUserList) {
        network->sendMessage(user->getAgent()->getToken(), json(startLoungeGameResponse).dump());
    }
}
