#include "Character.h"

class Room;

namespace BangCharacter {
    class PaulRegret : public Character {
    public:
        PaulRegret(Room *room);

        static const std::string &getName();

        const std::string &getCharacterName() const override;

        static const std::string &getFeature();

        const std::string &getCharacterFeature() const override;


        int getMaxHp() const override;

        int getAttackRange() const override;

        int getAddAttackRange() const override;

        int getDefendAttackRange() const override;

        bool isHasMultiAttack() const override;

    private:
        static const std::string name;
        static const std::string feature;

        const int maxHp = 3;
        const int attackRange = 0;
        const int addRange = 1;
        const int defendRange = 0;
        const bool hasMultiAttack = false;
    };

}
