//
// Created by edge on 2019-10-01.
//

#ifndef BIGBANGREMAKE_ROOMMANAGER_H
#define BIGBANGREMAKE_ROOMMANAGER_H

#include "Room.h"
#include <vector>

class RoomManager {
public:
    static RoomManager *getInstance();

    Room *createRoom();

    Room *searchRoom(Player *player) const;

    void removeRoom(Room *targetRoom);

private:
    static RoomManager *instance;
    std::vector<Room *> roomList;
};


#endif //BIGBANGREMAKE_ROOMMANAGER_H
