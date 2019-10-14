#pragma once

#include <vo/ChooseCardFromAnotherPlayerResponse.h>
#include <condition_variable>
#include "Card.h"
#include "Player.h"
#include "nlohmann/json.hpp"

class Room;
namespace BangCard {
    class CatBalou : public Card {
    public:
        CatBalou(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool useCardEffect(Room *room, Player *myself, Player *target) override;

        void handleMessage(const nlohmann::json &jsonMessage) override;

    private:
        static const std::string name;
        static const std::string feature;
        Response::PlayerCard::ChooseCardFromAnotherPlayerResponse response;
        std::condition_variable conditionVariable;
        std::mutex conditionVariableMutex;

    };

}
