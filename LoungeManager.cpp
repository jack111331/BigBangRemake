#include "LoungeManager.h"
#include "Lounge.h"
#include "User.h"

LoungeManager *LoungeManager::instance = nullptr;

LoungeManager *LoungeManager::getInstance() {
    if (LoungeManager::instance == nullptr) {
        LoungeManager::instance = new LoungeManager();
    }
    return LoungeManager::instance;
}

void LoungeManager::addUserToNewLounge(User *user) {
    auto lounge = new Lounge(user);
    loungeList.push_back(lounge);
    lounge->joinLounge(user);
    lounge->changeRoomOwner(user);
}

void LoungeManager::addUserToLounge(User *user, uint32_t id) {
    for (auto &lounge : loungeList) {
        if (lounge->getId() && lounge->getLoungeSize() < Lounge::MAX_LOUNGE_SIZE) {
            lounge->joinLounge(user);
        }
    }
}

uint32_t LoungeManager::searchLoungeId(User *user) const {
    return searchLoungeIdByUserId(user->getId());
}

uint32_t LoungeManager::searchLoungeIdByUserId(uint32_t id) const {
    for (auto lounge : loungeList) {
        if (lounge->searchUserInLounge(id)) {
            return lounge->getId();
        }
    }
    return USER_NOT_FOUND;
}

Lounge *LoungeManager::searchLounge(User *user) const {
    return searchLounge(user->getId());
}

Lounge *LoungeManager::searchLounge(uint32_t userId) const {
    for (auto lounge : loungeList) {
        if (lounge->searchUserInLounge(userId)) {
            return lounge;
        }
    }
    return nullptr;
}

const std::vector<Lounge *> &LoungeManager::getLoungeList() const {
    return loungeList;
}

void LoungeManager::removeLounge(Lounge *targetLounge) {
    for (auto lounge = loungeList.begin(); lounge != loungeList.end(); ++lounge) {
        if (*lounge == targetLounge) {
            delete *lounge;
            loungeList.erase(lounge);
            break;
        }
    }
}


void LoungeManager::removeUserFromLounge(User *user) {
    auto targetLounge = searchLounge(user);
    if (targetLounge == nullptr) {
        return;
    }
    if (user == targetLounge->getRoomOwner()) {
        targetLounge->changeRoomOwner(targetLounge->getFirstUser());
    }
    targetLounge->exitLounge(user);
    if (targetLounge->getLoungeSize() <= 0) {
        removeLounge(targetLounge);
    }
}

LoungeManager::~LoungeManager() {
    for (auto it = loungeList.begin(); it != loungeList.end(); ++it) {
        delete *it;
        loungeList.erase(it);
    }
    delete LoungeManager::instance;
    LoungeManager::instance = nullptr;
}

