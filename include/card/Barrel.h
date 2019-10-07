#pragma once

#include <GameEventListener.h>
#include "EquipmentCard.h"
#include "Player.h"

class Room;

namespace BangCard {

    class Barrel : public EquipmentCard{
    public:
        Barrel(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool onEquip(Room *room, Card *card, Player *equiper);

        bool onPreLossBlood(Room *room, Player *loser);

        bool onUnequip(Room *room, Card *card, Player *unequiper);

    private:
        static const std::string name;
        static const std::string feature;
        GameEventListener *listener;
    };

}
