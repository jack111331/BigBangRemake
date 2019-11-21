//
// Created by edge on 2019-10-18.
//

#include <vo/UpdatePlayerInfoRequest.h>
#include <vo/ShowDetermineCardRequest.h>
#include <vo/ChooseCharacterRequest.h>
#include <vo/RetrieveGameInfoRequest.h>
#include <vo/InformUseCardRequest.h>
#include <vo/InformFoldCardRequest.h>
#include "PlayerService.h"
#include "Player.h"
#include "User.h"
#include "Room.h"

using nlohmann::json;

PlayerService::PlayerService() {
    this->network = Network::getInstance();
}

template<typename T>
json PlayerService::packAsJson(std::string requestName, T request) {
    json completeRequest = {{"player", {requestName, request}}};
    return completeRequest;
}

void
PlayerService::sendRetrieveGameInfoRequest(Player *sendToPlayer, Room *room, const std::vector<Player *> &playerList,
                                           const std::vector<Card *> &cardList) {
    std::vector<Request::Player::PlayerInfo> playerInfoList;
    for (auto player : playerList) {
        if (player != sendToPlayer) {
            playerInfoList.push_back({
                                             player->getAgent()->getUser()->getName(),
                                             room->getPositionByPlayer(player), ::toString(player->getIdentity())
                                     });
        }
    }
    std::vector<Request::Player::CardInfo> cardInfoList;
    for (auto card : cardList) {
        cardInfoList.push_back({card->getCardName(), card->getId(), ::toString(card->getSuit()), card->getNumber()});
    }
    Request::Player::RetrieveGameInfoRequest request = {
            room->getPositionByPlayer(sendToPlayer), ::toString(sendToPlayer->getIdentity()), playerInfoList,
            cardInfoList
    };
    json retrieveGameInfoRequest = packAsJson("retrieveGameInfo", request);
    network->sendMessage(sendToPlayer->getAgent()->getToken(), json(retrieveGameInfoRequest).dump());
}

void PlayerService::sendInformUseCardRequest(Player *sendToPlayer) {
    Request::Player::InformUseCardRequest request = {};
    json informUseCardRequest = packAsJson("informUseCard", request);
    network->sendMessage(sendToPlayer->getAgent()->getToken(), json(informUseCardRequest).dump());
}

void PlayerService::sendInformFoldCardRequest(Player *sendToPlayer) {
    Request::Player::InformFoldCardRequest request = {};
    json informFoldCardRequest = packAsJson("informFoldCard", request);
    network->sendMessage(sendToPlayer->getAgent()->getToken(), json(informFoldCardRequest).dump());
}

void PlayerService::sendShowDetermineCardRequest(const std::vector<Player *> &sendToPlayerList, uint32_t cardId) {
    Request::Player::ShowDetermineCardRequest request = {cardId};
    json showDetermineCardRequest = packAsJson("showDetermineCard", request);
    for (auto player : sendToPlayerList) {
        network->sendMessage(player->getAgent()->getToken(), json(showDetermineCardRequest).dump());
    }
}

void PlayerService::sendChooseCardRequest(Player *sendToPlayer, const std::vector<std::string> &characterNameList) {
    Request::Player::ChooseCharacterRequest request = {characterNameList};
    json chooseCharacterRequest = packAsJson("chooseCharacter", request);
    network->sendMessage(sendToPlayer->getAgent()->getToken(), json(chooseCharacterRequest).dump());
}

void PlayerService::sendUpdatePlayerInfoRequest(const std::vector<Player *> &sendToPlayerList, Player *player) {
    std::string identity = player->isDead() ? toString(player->getIdentity()) : toString(Identity::Unknown);
    Request::Player::UpdatePlayerInfoRequest request = {
            identity, player->getCharacter()->getCharacterName(), player->getHp(),
            player->getHoldingCardAmount(), player->isDead()
    };
    json updatePlayerInfoRequest = packAsJson("updatePlayerInfo", request);
    for (auto player : sendToPlayerList) {
        network->sendMessage(player->getAgent()->getToken(), json(updatePlayerInfoRequest).dump());
    }
}
