//
// Created by edge on 2019-10-04.
//

#include "Agent.h"

#include <utility>
Agent::Agent(websocketpp::connection_hdl hdl) : token(std::move(hdl)), user(nullptr), player(nullptr) {

}
const websocketpp::connection_hdl &Agent::getToken() const {
    return token;
}

void Agent::handleMessage(const std::string &message) {
    // TODO handle message
}


User *Agent::getUser() const {
    return user;
}

void Agent::setUser(User *user) {
    this->user = user;
}

Player *Agent::getPlayer() const {
    return player;
}

void Agent::setPlayer(Player *player) {
    this->player = player;
}
