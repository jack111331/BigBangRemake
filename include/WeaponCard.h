#pragma once

#include "Card.h"
#include "EquipmentCard.h"

class WeaponCard : public EquipmentCard {
public:
    WeaponCard(Room *room, int number, Suit suit);

    virtual int getAttackRange() const = 0;

    virtual int getDefendRange() const = 0;

    virtual bool isMultiAttack() const = 0;

    virtual bool useCardEffect(Room *room, Player *myself, Player *target);

};
