//
// Created by edge on 2019-10-04.
//

#include "Agent.h"
#include <utility>
#include "nlohmann/json.hpp"
#include "User.h"
#include "Player.h"
using nlohmann::json;
Agent::Agent(websocketpp::connection_hdl hdl) : token(std::move(hdl)), user(nullptr), player(nullptr) {

}
const websocketpp::connection_hdl &Agent::getToken() const {
    return token;
}

void Agent::handleMessage(const std::string &message) {
    json jsonMessage = json(message);
    if(jsonMessage.at("user")) {
        if(user) {
            user->handleMessage(jsonMessage.at("user"));
        } else {
            // TODO record error
        }
    } else if(jsonMessage.at("player")) {
        if(player) {
            player->handleMessage(jsonMessage.at("player"));
        } else {
            // TODO record error
        }
    }
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

Agent::~Agent() {
    delete user;
    delete player;
}