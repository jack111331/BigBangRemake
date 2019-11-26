#include <vo/ChangeNicknameRequest.h>
#include <vo/RetrieveLoungeListInfoResponse.h>
#include <LoungeManager.h>
#include <Network.h>
#include <vo/JoinLoungeRequest.h>
#include <vo/RetrieveLoungeInfoResponse.h>
#include <vo/ReadyInLoungeRequest.h>
#include <RoomManager.h>
#include <Logger.h>
#include "User.h"

using nlohmann::json;

User::User(Agent *agent) : agent(agent), name(""), money(0), win(0), lose(0), id(0) {
    this->userService = new UserService();
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
    if (jsonMessage.find("registerAndLogin") != jsonMessage.end()) {

    } else if (jsonMessage.find("changeNickname") != jsonMessage.end()) {
        Request::User::ChangeNicknameRequest request = jsonMessage.at(
                "changeNickname").get<Request::User::ChangeNicknameRequest>();
        this->name = request.nickname;
    } else if (jsonMessage.find("retrieveLoungeListInfo") != jsonMessage.end()) {
        userService->sendRetrieveLoungeListInfoResponse(this, loungeManager->getLoungeList());
    } else if (jsonMessage.find("joinLounge") != jsonMessage.end()) {
        Request::User::JoinLoungeRequest request = jsonMessage.at(
                "changeNickname").get<Request::User::JoinLoungeRequest>();
        loungeManager->addUserToLounge(this, request.loungeId);
    } else if (jsonMessage.find("leaveLounge") != jsonMessage.end()) {
        loungeManager->removeUserFromLounge(this);
    } else if (jsonMessage.find("retrieveLoungeInfo") != jsonMessage.end()) {
        userService->sendRetrieveLoungeInfoResponse(this, loungeManager->searchLounge(this));
    } else if (jsonMessage.find("readyInLounge") != jsonMessage.end()) {
        Request::User::ReadyInLoungeRequest request = jsonMessage.at(
                "readyInLounge").get<Request::User::ReadyInLoungeRequest>();
        auto lounge = loungeManager->searchLounge(this);
        lounge->setReadyState(this, request.ready);
    } else if (jsonMessage.find("startLoungeGame") != jsonMessage.end()) {
        auto lounge = loungeManager->searchLounge(this);
        auto roomManager = RoomManager::getInstance();
        if (lounge->getRoomOwner() == this && lounge->isAllUserReady() && lounge->getLoungeSize() == Lounge::MAX_LOUNGE_SIZE) {
            auto room = roomManager->createRoom();
            for (auto user : lounge->getUserList()) {
                room->playerJoin(user->getAgent());
            }
            room->startGame();
            userService->sendStartLoungeGameResponse(lounge->getUserList());
        }
    } else {
        auto logger = Logger::getLogger("[User]");
        logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
    }
}

User::~User() {
    delete this->userService;
}