//
// Created by edge on 2019-10-04.
//

#include "Agent.h"
#include <utility>
#include <Logger.h>
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
    auto logger = Logger::getLogger("Agent");
    logger->info("jsonMessage={}", jsonMessage.dump());
    if(jsonMessage.find("user") != jsonMessage.end()) {
        if(user) {
            user->handleMessage(jsonMessage.at("user"));
        } else {
            logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
        }
    } else if(jsonMessage.find("player") != jsonMessage.end()) {
        if(player) {
            player->handleMessage(jsonMessage.at("player"));
        } else {
            logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
        }
    } else {
        logger->error("Wrong Message, jsonMessage={}", jsonMessage.dump());
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