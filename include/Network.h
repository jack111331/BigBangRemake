//
// Created by edge on 2019-10-01.
//

#ifndef BIGBANGREMAKE_NETWORK_H
#define BIGBANGREMAKE_NETWORK_H

#include "websocketpp/server.hpp"
#include "websocketpp/config/asio.hpp"
#include "Agent.h"

typedef websocketpp::server<websocketpp::config::asio> server;

class Network {
public:
    Network();
    static Network *getInstance();
    void setup();
    void onOpen(websocketpp::connection_hdl hdl);
    void onMessage(websocketpp::connection_hdl hdl, server::message_ptr msg);
    void sendMessage(websocketpp::connection_hdl hdl, const std::string &message);
    void onClose(const websocketpp::connection_hdl& hdl);
    ~Network();
private:
    static Network *instance;
    static const uint16_t PORT = 27011;
    server * gameServer;
    std::map<websocketpp::connection_hdl, Agent *, std::owner_less<std::weak_ptr<void>>> agentSet;
};


#endif //BIGBANGREMAKE_NETWORK_H
