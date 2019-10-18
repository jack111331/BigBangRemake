//
// Created by edge on 2019-10-18.
//

#ifndef BIGBANGREMAKE_PLAYERSERVICE_H
#define BIGBANGREMAKE_PLAYERSERVICE_H


#include "Network.h"

class PlayerService {
public:
    PlayerService();

    template<typename T>
    nlohmann::json packAsJson(std::string requestName, T request);

    void sendShowDetermineCardRequest(const std::vector<Player *>& sendToPlayerList, uint32_t cardId);
    void sendStartGameRequest(const std::vector<Player *>& sendToPlayerList);

    void sendChooseCardRequest(Player * sendToPlayer, const std::vector<std::string> &characterNameList);


private:
    Network *network;
};


#endif //BIGBANGREMAKE_PLAYERSERVICE_H
