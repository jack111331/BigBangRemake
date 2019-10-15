#pragma once

#include <vo/ResistAttackResponse.h>
#include "Card.h"
#include "Player.h"

class Room;

namespace BangCard {
    class Bang : public Card {
    public:
        Bang(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool useCardEffect(Room *room, Player *myself, Player *target) override;

        void handleMessage(const nlohmann::json &jsonMessage) override;

    private:
        static const std::string name;
        static const std::string feature;
        Response::PlayerCard::ResistAttackResponse response;
    };
}
