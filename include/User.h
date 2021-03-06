#pragma once

#include <stdint.h>
#include <string>
#include "Agent.h"
#include "nlohmann/json.hpp"
#include "UserService.h"

class User {
public:
    User(Agent *agent);

    Agent *getAgent() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    int getMoney() const;

    void setMoney(int money);

    int getWin() const;

    void setWin(int win);

    int getLose() const;

    void setLose(int lose);

    uint32_t getId() const;

    void setId(uint32_t id);

    void handleMessage(const nlohmann::json &jsonMessage);

    ~User();

private:
    Agent *agent;
    UserService *userService;
    std::string name;
    int money;
    int win;
    int lose;
    uint32_t id;
};
