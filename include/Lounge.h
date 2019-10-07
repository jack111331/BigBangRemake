#pragma once

#include <vector>
#include <map>
#include <stdint.h>
#include <thread>

class User;
class Room;

class Lounge {
public:
    Lounge(User *roomOwner);

    uint32_t getId() const;

    void setId(uint32_t id);

    void joinLounge(User *user);

    size_t getLoungeSize();

    User *getFirstUser();

    std::vector<User *> &getAllUser();

    void changeRoomOwner(User *user);

    void setRoomOwner(User *roomOwner);

    User *getRoomOwner();

    bool searchUserInLounge(User *user);

    bool searchUserInLounge(uint32_t ID);

    bool isAllUserReady();

    bool getReadyState(User *user);

    void setReadyState(User *user, bool state);

    void exitLounge(User *user);

    //  Room * getRoom();
    //    bool initGame();

    bool getEnableExclusiveCard() const;

    void setEnableExclusiveCard(bool enable);

    ~Lounge();

private:
    uint32_t id;
    std::vector<User *> userList;
    std::map<User *, bool> readyMap;
    //  Room * room;
    std::thread GameLoopThread;
    bool enableExclusiveCard = false;
    User *roomOwner;
    // Owner is for when all user ready, who will decide the game will start
};