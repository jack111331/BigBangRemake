#pragma once

#include "Card.h"
#include "Player.h"

class CRoom;
namespace BangCard {
    class Saloon : public Card {
    public:
        Saloon(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool useCardEffect(Room *room, Player *myself, Player *target) override;

    private:
        static const std::string name;
        static const std::string feature;
    };

}
