#pragma once

#include <GameEventListener.h>
#include "EquipmentCard.h"
#include "Player.h"

class Room;
namespace BangCard {
    class Jail : public EquipmentCard {
    public:
        Jail(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        bool useCardEffect(Room *room, Player *myself, Player *target) override;

        bool onEquip(Room *room, Card *card, Player *equiper);

        bool onDrawCard(Room *room, Player *Drawer);

        bool onUnequip(Room *room, Card *card, Player *unequiper);

    private:
        static const std::string name;
        static const std::string feature;
        GameEventListener *listener;
    };

}
