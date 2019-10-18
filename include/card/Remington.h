#pragma once

#include "WeaponCard.h"
#include "Player.h"

class Room;
namespace BangCard {
    class Remington : public WeaponCard {
    public:
        Remington(Room *room, int number, Suit suit);

        static const std::string &getName();

        const std::string &getCardName() const override;

        static const std::string &getFeature();

        const std::string &getCardFeature() const override;

        int getAttackRange() const override;

        int getAddAttackRange() const override;

        int getDefendRange() const override;

        bool isMultiAttack() const override;

    private:
        static const std::string name;
        static const std::string feature;
        static const int attackRange = 1;
        static const int addAttackRange = 0;
        static const int defendRange = 0;
        static const bool multiAttack = false;

    };

}
