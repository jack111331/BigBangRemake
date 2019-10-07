#pragma once

#include <GameEventListener.h>
#include "Card.h"
#include "Player.h"

class Room;

namespace BangCard {
    class Beer : public Card {
    public:
        Beer(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool useCardEffect(Room *room, Player *myself, Player *target) override;

        void onLossBlood(Room *room, Player *loser, Player *attacker);

    private:
        static const std::string name;
        static const std::string feature;
        GameEventListener *listener;
    };

}
