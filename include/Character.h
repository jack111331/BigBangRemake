#pragma once

#include <string>
#include <vector>

class Player;

class Plague;

class Room;

class Character {
public:
    Character(Room *room);

    static uint32_t getCharacterId();

    virtual const std::string &getCharacterName() const = 0;

    virtual const std::string &getCharacterFeature() const = 0;

    virtual int getMaxHp() const = 0;

    virtual int getAttackRange() const = 0;

    virtual int getAddAttackRange() const = 0;

    virtual int getDefendAttackRange() const = 0;

    virtual bool isHasMultiAttack() const = 0;

    uint32_t getId() const;

    // Define character normal activity
    virtual void drawCard(Room *room, Player *player);

protected:
    static uint32_t characterId;

private:
    uint32_t id;
};
