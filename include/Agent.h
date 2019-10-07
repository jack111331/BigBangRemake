//
// Created by edge on 2019-10-04.
//

#ifndef BIGBANGREMAKE_AGENT_H
#define BIGBANGREMAKE_AGENT_H

#include <websocketpp/common/connection_hdl.hpp>

class User;
class Player;

class Agent {
public:
    Agent(websocketpp::connection_hdl hdl);

    const websocketpp::connection_hdl &getToken() const;

    void handleMessage(const std::string &message);

    User *getUser() const;

    void setUser(User *user);

    Player *getPlayer() const;

    void setPlayer(Player *player);

private:
    websocketpp::connection_hdl token;
    User *user;
    Player *player;

};


#endif //BIGBANGREMAKE_AGENT_H
