//
// Created by edge on 2019-10-18.
//

#ifndef BIGBANGREMAKE_PLAYERSERVICE_H
#define BIGBANGREMAKE_PLAYERSERVICE_H


#include "Network.h"

class Card;
class Room;

class PlayerService {
public:
    PlayerService();

    template<typename T>
    nlohmann::json packAsJson(std::string requestName, T request);

    void sendRetrieveGameInfoRequest(Player *sendToPlayer, Room *room, const std::vector<Player *> &playerList, const std::vector<Card *> &cardList);

    void sendInformUseCardRequest(Player *sendToPlayer);

    void sendInformFoldCardRequest(Player *sendToPlayer);

    void sendShowDetermineCardRequest(const std::vector<Player *>& sendToPlayerList, uint32_t cardId);

    void sendChooseCardRequest(Player * sendToPlayer, const std::vector<std::string> &characterNameList);

private:
    Network *network;
};


#endif //BIGBANGREMAKE_PLAYERSERVICE_H
