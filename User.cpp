#include <vo/ChangeNicknameRequest.h>
#include <vo/RetrieveLoungeListInfoResponse.h>
#include <LoungeManager.h>
#include <Network.h>
#include <vo/JoinLoungeRequest.h>
#include <vo/RetrieveLoungeInfoResponse.h>
#include <vo/ReadyInLoungeRequest.h>
#include <RoomManager.h>
#include "User.h"

using nlohmann::json;

User::User(Agent *agnet) : agent(agent), name(""), money(0), win(0), lose(0), id(0) {
}


Agent *User::getAgent() const {
    return agent;
}

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    this->name = name;
}

int User::getMoney() const {
    return money;
}

void User::setMoney(int money) {
    this->money = money;
}

int User::getWin() const {
    return win;
}

void User::setWin(int win) {
    this->win = win;
}

int User::getLose() const {
    return lose;
}

void User::setLose(int lose) {
    this->lose = lose;
}

uint32_t User::getId() const {
    return id;
}

void User::setId(uint32_t id) {
    this->id = id;
}

void User::handleMessage(const json &jsonMessage) {
    auto loungeManager = LoungeManager::getInstance();
    auto network = Network::getInstance();
    if (jsonMessage.at("registerAndLogin")) {

    } else if (jsonMessage.at("changeNickname")) {
        Request::User::ChangeNicknameRequest request = jsonMessage.at(
                "changeNickname").get<Request::User::ChangeNicknameRequest>();
        this->name = request.nickname;
    } else if (jsonMessage.at("retrieveLoungeListInfo")) {
        Response::User::RetrieveLoungeListInfoResponse response;
        for (const auto lounge : loungeManager->getLoungeList()) {
            response.loungeList.push_back({lounge->getId(), lounge->getLoungeSize()});
        }
        network->sendMessage(this->agent->getToken(), nlohmann::json(response).dump());
    } else if (jsonMessage.at("joinLounge")) {
        Request::User::JoinLoungeRequest request = jsonMessage.at(
                "changeNickname").get<Request::User::JoinLoungeRequest>();
        loungeManager->addUserToLounge(this, request.loungeId);
    } else if (jsonMessage.at("leaveLounge")) {
        loungeManager->removeUserFromLounge(this);
    } else if (jsonMessage.at("retrieveLoungeInfo")) {
        Response::User::RetrieveLoungeInfoResponse response;
        auto lounge = loungeManager->searchLounge(this);
        auto userList = lounge->getUserList();
        for (const auto user : userList) {
            response.memberList.push_back({user->getId(), user->getName(), lounge->getReadyState(user)});
        }
        network->sendMessage(this->agent->getToken(), nlohmann::json(response).dump());
    } else if (jsonMessage.at("readyInLounge")) {
        Request::User::ReadyInLoungeRequest request = jsonMessage.at(
                "readyInLounge").get<Request::User::ReadyInLoungeRequest>();
        auto lounge = loungeManager->searchLounge(this);
        lounge->setReadyState(this, request.ready);
    } else if (jsonMessage.at("startLoungeGame")) {
        auto lounge = loungeManager->searchLounge(this);
        auto roomManager = RoomManager::getInstance();
        if(lounge->getRoomOwner() == this && lounge->isAllUserReady()) {
            auto room = roomManager->createRoom();
            for(auto user : lounge->getUserList()) {
                room->playerJoin(user->getAgent());
            }
        }
    } else {
        // TODO log error
    }
}