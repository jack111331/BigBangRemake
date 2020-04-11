#include "Lounge.h"
#include "User.h"

Lounge::Lounge(User *roomOwner) {
    this->id = (uint32_t) ((uint64_t) this & 0xffffffff);
    this->threadDone = false;
    this->syncThread = std::thread(std::bind(&Lounge::pollingForSync, this));
    syncThread.detach();
}

void Lounge::pollingForSync() {
    auto userService = new UserService();
    while (!threadDone) {
        if (dirty) {
            for (auto user : userList) {
                userService->sendRetrieveLoungeInfoResponse(user, this);
            }
            dirty = false;
        }
        std::this_thread::sleep_for(std::chrono::seconds(SYNC_TIME_IN_SECOND));
    }
}

uint32_t Lounge::getId() const {
    return id;
}

void Lounge::joinLounge(User *user) {
    userList.push_back(user);
    readyMap.insert(std::pair<User *, bool>(user, false));
    this->dirty = true;
}

size_t Lounge::getLoungeSize() {
    return userList.size();
}

User *Lounge::getFirstUser() {
    return userList.at(0);
}

std::vector<User *> &Lounge::getUserList() {
    return userList;
}

bool Lounge::searchUserInLounge(User *user) {
    return searchUserInLounge(user->getId());
}

bool Lounge::searchUserInLounge(uint32_t id) {
    for (auto user : userList) {
        if (user->getId() == id) {
            return true;
        }
    }
    return false;
}

void Lounge::changeRoomOwner(User *user) {
    this->roomOwner = user;
    this->dirty = true;
}

User *Lounge::getRoomOwner() {
    return roomOwner;
}

bool Lounge::isAllUserReady() {
    for (auto &it : readyMap) {
        if (!it.second && it.first != roomOwner) {
            return false;
        }
    }
    return true;
}

bool Lounge::getReadyState(User *user) {
    if (readyMap.find(user) != readyMap.end()) {
        return readyMap.at(user);
    }
    return false;
}

void Lounge::setReadyState(User *user, bool state) {
    if (readyMap.at(user) != state) {
        readyMap.at(user) = state;
        this->dirty = true;
    }
}

void Lounge::exitLounge(User *user) {
    for (auto it = userList.begin(); it != userList.end(); ++it) {
        if (*it == user) {
            userList.erase(it);
            readyMap.erase(user);
            this->dirty = true;
            break;
        }
    }
}

bool Lounge::getEnableExclusiveCard() const {
    return enableExclusiveCard;
}

void Lounge::setEnableExclusiveCard(bool enable) {
    this->enableExclusiveCard = enable;
}

Lounge::~Lounge() {
    threadDone = true;
}
