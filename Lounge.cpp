#include "Lounge.h"
#include "User.h"
Lounge::Lounge(User *roomOwner){

}

void Lounge::setRoomOwner(User *roomOwner) {
    this->roomOwner = roomOwner;
}

uint32_t Lounge::getId() const {
    return id;
}

void Lounge::setId(uint32_t id) {
    this->id = id;
}

void Lounge::joinLounge(User *user) {
    userList.push_back(user);
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

bool Lounge::searchUserInLounge(uint32_t ID) {
    for (int i = 0; i < static_cast<int>(userList.size()); ++i) {
        if (userList[i]->getId() == ID) {
            return true;
        }
    }
    return false;
}

void Lounge::changeRoomOwner(User *user) {
    this->roomOwner = user;
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
    if(readyMap.find(user) != readyMap.end()) {
        return readyMap.at(user);
    }
    return false;
}

void Lounge::setReadyState(User *user, bool state) {
    readyMap.at(user) = state;
}

void Lounge::exitLounge(User *user) {
    for (auto it = userList.begin(); it != userList.end(); ++it) {
        if (*it == user) {
            userList.erase(it);
            readyMap.erase(user);
            break;
        }
    }
}

//Room *Lounge::getRoom() {
//    return this->room;
//}

//bool Lounge::initGame() {
//    if (!isAllUserReady() || userSet.size() < 4 || userSet.size() > 7) {
//        roomOwner->SendMessage("Send Message", NSWrapInfo::WrapStartGame(nullptr, 0));
//        return false;
//    }
//    //Start game
//    room = new Room(this);
//    for (std::vector<User *>::iterator it = userSet.begin(); it != userSet.end(); ++it) {
//        room->playerJoin(*it);
//    }
//    //game loop
//    GameLoopThread = std::thread(Room::gameLoop, room);
//    return true;
//}

bool Lounge::getEnableExclusiveCard() const {
    return enableExclusiveCard;
}

void Lounge::setEnableExclusiveCard(bool enable) {
    this->enableExclusiveCard = enable;
}

Lounge::~Lounge() {
//    delete room;
    GameLoopThread.detach();
}

