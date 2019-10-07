#pragma once

#include <map>
#include <stdint.h>
#include "Lounge.h"

class User;

class LoungeManager {
public:
    static LoungeManager *getInstance();

    void addUserToNewLounge(User *user);

    void addUserToLounge(User *user, uint32_t id);

    uint32_t searchLoungeId(User *user) const;

    uint32_t searchLoungeIdByUserId(uint32_t id) const;

    Lounge *searchLounge(User *user) const;

    Lounge *searchLounge(uint32_t id) const;

    void removeLounge(Lounge *targetLounge);

    void removeUserFromLounge(User *user);

    const std::vector<Lounge *> &getLoungeList() const;

    ~LoungeManager();

private:
    static LoungeManager *instance;
    std::vector<Lounge *> loungeList;
    static const uint32_t USER_NOT_FOUND = 0xFFFFFFFF;
};
