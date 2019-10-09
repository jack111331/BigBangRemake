#include "User.h"

using nlohmann::json;

User::User(Agent *agnet) : agent(agent), name(""), money(0), win(0), lose(0), id(0) {
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
    // TODO handle message
}