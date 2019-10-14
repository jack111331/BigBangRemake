#include "GameEventListener.h"
#include "Player.h"
#include "Room.h"
#include "Card.h"

GameEventListener::GameEventListener() : onPreLossBlood(nullptr), onLossBlood(nullptr), onDeath(nullptr),
                                         onPreDrawCard(nullptr), onEquip(nullptr), onUnequip(nullptr),
                                         onRoundEnd(nullptr) {
}

void EventSubject::subscribe(GameEventListener *observer) {
    subscriberList.push_back(observer);
}

void EventSubject::unsubscribe(GameEventListener *observer) {
    for (auto subscriber = subscriberList.begin(); subscriber != subscriberList.end(); ++subscriber) {
        if (*subscriber == observer) {
            subscriberList.erase(subscriber);
            break;
        }
    }
}

bool EventSubject::notifyPreLossBloodEvent(Room *room, Player *loser) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onPreLossBlood) {
            subscriber->onPreLossBlood(room, loser);
        }
    }
}

bool EventSubject::notifyLossBloodEvent(Room *room, Player *loser, Player *attacker) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onLossBlood) {
            subscriber->onLossBlood(room, loser, attacker);
        }
    }

}

bool EventSubject::notifyDeathEvent(Room *room, Player *deadPerson, Player *attacker) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onDeath) {
            subscriber->onDeath(room, deadPerson, attacker);
        }
    }
}

bool EventSubject::notifyPreDrawCardEvent(Room *room, Player *drawer) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onPreDrawCard) {
            subscriber->onPreDrawCard(room, drawer);
        }
    }
}

bool EventSubject::notifyEquipEvent(Room *room, Card *card, Player *equiper) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onEquip) {
            subscriber->onEquip(room, card, equiper);
        }
    }
}

bool EventSubject::notifyUnequipEvent(Room *room, Card *card, Player *unequiper) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onUnequip) {
            subscriber->onUnequip(room, card, unequiper);
        }
    }
}

bool EventSubject::notifyRoundEndEvent(Room *room, Player *roundEnder) {
    for (auto subscriber:subscriberList) {
        if (subscriber->onRoundEnd) {
            subscriber->onRoundEnd(room, roundEnder);
        }
    }
}
