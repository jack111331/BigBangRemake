#include <GameEventListener.h>
#include "Character.h"

class Room;

namespace BangCharacter {
    class VultureSam : public Character {
    public:
        VultureSam(Room *room);

        static const std::string &getName();

        const std::string &getCharacterName() const override;

        static const std::string &getFeature();

        const std::string &getCharacterFeature() const override;


        int getMaxHp() const override;

        int getAttackRange() const override;

        int getAddRange() const override;

        int getDefendRange() const override;

        bool isHasMultiAttack() const override;

        void onDeath(Room *room, Player *deadPerson, Player *attacker);

        ~VultureSam();

    private:
        static const std::string name;
        static const std::string feature;

        const int maxHp = 4;
        const int attackRange = 1;
        const int addRange = 0;
        const int defendRange = 0;
        const bool hasMultiAttack = false;

        GameEventListener *listener;
    };

}
