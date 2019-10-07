#include "card/Duel.h"
#include <string>
#include "Room.h"
#include "Action.h"

using std::string;
using namespace BangCard;

const string Duel::name = "Duel";
const string Duel::feature = "The Duelee first and Dueler second, round robin to use their Bang!, if one side has no Bang! remain, then he will loss 1 HP.";

Duel::Duel(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &Duel::getName() {
    return Duel::name;
}

const std::string &Duel::getCardName() const {
    return Duel::name;
}

const std::string &Duel::getFeature() {
    return Duel::feature;
}

const std::string &Duel::getCardFeature() const {
    return Duel::feature;
}

bool Duel::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!target->isDead()) {
        if (!Card::useCardEffect(room, myself, target)) {
            return false;
        }
        int MyTurn = 0;
        bool isEnd = 0;
        while (!isEnd) {
            isEnd = std::max(isEnd,
                             Action::attack(room, MyTurn ? target : myself, MyTurn ? myself : target, "Bang!"));
            MyTurn ^= 1;
        }
        return true;
    }
    return false;
}