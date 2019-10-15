//
// Created by edge on 2019-10-01.
//

#include "RoomManager.h"
#include "User.h"
RoomManager *RoomManager::instance = nullptr;
RoomManager *RoomManager::getInstance() {
    if(RoomManager::instance == nullptr) {
        RoomManager::instance = new RoomManager();
    }
    return RoomManager::instance;
}

Room *RoomManager::createRoom() {
    Room *room = new Room();
    roomList.push_back(room);
    return room;
}

Room *RoomManager::searchRoom(Player *player) const {
    for(auto room : roomList) {
        if(room->getPositionByPlayer(player) != room->getPlayerAmount()) {
            return room;
        }
    }
    return nullptr;
}

void RoomManager::removeRoom(Room *targetRoom) {
    for(auto it = roomList.begin();it != roomList.end();++it) {
        if(*it == targetRoom) {
            delete *it;
            roomList.erase(it);
            break;
        }
    }
}