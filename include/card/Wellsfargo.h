#pragma once

#include "Card.h"
#include "Player.h"

class Room;
namespace BangCard {
    class Wellsfargo : public Card {
    public:
        Wellsfargo(Room *room, int number, Suit suit);

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
