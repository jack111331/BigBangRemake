//
// Created by edge on 2019-10-01.
//

#include "Network.h"
#include "User.h"

Network *Network::instance = nullptr;

Network::Network() {
    this->gameServer = new server();

    // Set logging level
    gameServer->set_error_channels(websocketpp::log::elevel::all);
    gameServer->set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);

    //initialize asio functionality
    gameServer->init_asio();

    gameServer->set_open_handler(std::bind(&Network::onOpen, this, std::placeholders::_1));
    gameServer->set_message_handler(
            std::bind(&Network::onMessage, this, std::placeholders::_1, std::placeholders::_2));
    gameServer->set_close_handler(std::bind(&Network::onClose, this, std::placeholders::_1));

    // Listen on port
    gameServer->listen(PORT);

    // Queues a connection accept operation
    gameServer->start_accept();

    // Start the Asio io_service run loop
    gameServer->run();

}

Network *Network::getInstance() {
    if (Network::instance == nullptr) {
        Network::instance = new Network();
    }
    return Network::instance;
}

void Network::onOpen(const websocketpp::connection_hdl &hdl) {
    auto agent = new Agent(hdl);
    auto user = new User(agent);
    agent->setUser(user);
    agentSet.insert(std::pair<websocketpp::connection_hdl, Agent *>(hdl, agent));
}

void Network::onMessage(websocketpp::connection_hdl hdl, server::message_ptr msg) {
    std::thread thread(std::bind(&Agent::handleMessage, agentSet.at(hdl), std::placeholders::_1), msg->get_payload());
    thread.detach();
    // single thread approach
    //    agentSet.at(hdl)->handleMessage(msg->get_payload());
}

void Network::sendMessage(websocketpp::connection_hdl hdl, const std::string &message) {
    gameServer->send(hdl, message, websocketpp::frame::opcode::value::TEXT);
}

void Network::onClose(const websocketpp::connection_hdl &hdl) {
    delete agentSet.at(hdl);
    agentSet.erase(hdl);
}

Network::~Network() {
    delete gameServer;
}
