#pragma once

#include <map>
#include <functional>
#include "Player.h"

class Room;

class Player;

class GameEventListener {
public:
    GameEventListener();

    typedef std::function<bool(Room *, Card *, Player *)> cardCallback;
    typedef std::function<bool(Room *, Player *)> playerCallback;
    typedef std::function<void(Room *, Player *, Player *)> playerInteractCallback;

    playerCallback onPreLossBlood;
    playerInteractCallback onLossBlood;
    playerInteractCallback onDeath;
    playerCallback onPreDrawCard;
    cardCallback onEquip;
    cardCallback onUnequip;
    playerCallback onRoundEnd;

};

class EventSubject {
public:
    void subscribe(GameEventListener *observer);

    void unsubscribe(GameEventListener *observer);

    bool notifyPreLossBloodEvent(Room *room, Player *loser);

    bool notifyLossBloodEvent(Room *room, Player *loser, Player *attacker);

    bool notifyDeathEvent(Room *room, Player *deadPerson, Player *attacker);

    bool notifyPreDrawCardEvent(Room *room, Player *drawer);

    bool notifyEquipEvent(Room *room, Card *card, Player *equiper);

    bool notifyUnequipEvent(Room *room, Card *card, Player *unequiper);

    bool notifyRoundEndEvent(Room *room, Player *roundEnder);

private:
    std::vector<GameEventListener *> subscriberList;
};

