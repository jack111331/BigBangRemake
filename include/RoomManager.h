//
// Created by edge on 2019-10-01.
//

#ifndef BIGBANGREMAKE_ROOMMANAGER_H
#define BIGBANGREMAKE_ROOMMANAGER_H

#include "Room.h"
#include <vector>

class RoomManager {
public:
    RoomManager *getInstance();

    Room *createRoom();

    static void addUserToRoom(User *user, Room *room);

    Room *searchRoom(uint32_t id) const;

    void removeRoom(Room *targetRoom);

private:
    static RoomManager *instance;
    std::vector<Room *> roomList;
};


#endif //BIGBANGREMAKE_ROOMMANAGER_H
