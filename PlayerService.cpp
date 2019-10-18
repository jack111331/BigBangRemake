//
// Created by edge on 2019-10-18.
//

#include <vo/ShowDetermineCardRequest.h>
#include <vo/ChooseCharacterRequest.h>
#include "PlayerService.h"
#include "Player.h"

using nlohmann::json;

PlayerService::PlayerService() {
    this->network = Network::getInstance();
}

template<typename T>
json PlayerService::packAsJson(std::string requestName, T request) {
    json completeRequest = {{"player", {requestName, request}}};
    return completeRequest;
}

void PlayerService::sendShowDetermineCardRequest(const std::vector<Player *>& sendToPlayerList, uint32_t cardId) {
    Request::Player::ShowDetermineCardRequest request = {cardId};
    json showDetermineCardRequest = packAsJson("showDetermineCard", request);
    for (auto player : sendToPlayerList) {
        network->sendMessage(player->getAgent()->getToken(), json(showDetermineCardRequest).dump());
    }
}

void PlayerService::sendStartGameRequest(const std::vector<Player *>& sendToPlayerList) {
    Request::Player::ShowDetermineCardRequest request = {};
    json showDetermineCardRequest = packAsJson("startGame", request);
    for (auto player : sendToPlayerList) {
        network->sendMessage(player->getAgent()->getToken(), json(showDetermineCardRequest).dump());
    }
}

void PlayerService::sendChooseCardRequest(Player *sendToPlayer, const std::vector<std::string> &characterNameList) {
    Request::Player::ChooseCharacterRequest request = {characterNameList};
    json chooseCharacterRequest = packAsJson("chooseCharacter", request);
    network->sendMessage(sendToPlayer->getAgent()->getToken(), json(chooseCharacterRequest).dump());
}

