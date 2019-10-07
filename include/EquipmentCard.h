#pragma once

#include "Card.h"

class EquipmentCard : public Card {
public:
    EquipmentCard(Room *room, int number, Suit suit);

    virtual bool useCardEffect(Room *room, Player *myself, Player *target);
};
