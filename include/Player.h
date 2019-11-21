#pragma once

#include <string>
#include <vector>
#include "Character.h"
#include "Card.h"
#include "Agent.h"
#include "nlohmann/json.hpp"

enum class Identity {
    Sergeant = 0, //警長
    ChiefSergeant = 1, //副警長
    BadAss = 2, //歹徒
    Traitor = 3, //叛徒
    Unknown = 4
};

std::string toString(Identity identity);

enum class PlayerState {
    Waiting,
    MyTurn
};

class Room;

class Equipment;
// TODO a thread to detect player's state is dirty, if dirty, then update everyone in room
class Player {
public:
    Player(Agent *agent);

    // information update related
    void handleMessage(const nlohmann::json &jsonMessage);

    void informFinishUsingCard();

    void informFinishFoldingCard();

    // holding related
    void addCardToHolding(Card *card);

    Card *getRandomHoldingCard();

    size_t getHoldingCardAmount() const;

    Card *getCardInHoldingByName(const std::string &cardName);

    Card *getCardInHoldingById(uint32_t cardId);

    void removeCardInHolding(const Card *card);

    void removeCardFromMyselfById(uint32_t cardId);

    // getter & setter
    Agent *getAgent() const;

    Identity getIdentity() const;

    Character *getCharacter() const;

    Equipment *getEquipment() const;

    int getHp() const;

    int getMaxHp() const;

    const std::vector<Card *> &getHolding() const;

    bool isHasMultiAttack() const;

    int getAttackRange() const;

    int getAddAttackRange() const;

    int getDefendAttackRange() const;

    bool isAttacked() const;

    bool isDead() const;

    bool isDirty() const;

    void setIdentity(Identity identity);

    void setCharacter(Character *character);

    void setHp(int hp);

    void setAttacked(bool attacked);

    void setDead(bool dead);

    ~Player();

private:
    Agent *agent;
    Identity identity;
    Character *character = nullptr;
    Equipment *equipment = nullptr;
    int hp = 0;
    std::vector<Card *> holding;
    bool attacked = false; //是否已攻擊
    bool dead = false; //是否處於死亡狀態
    bool dirty = false;
};
