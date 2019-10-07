#pragma once

#include <string>

class Player;

class Card;

class Room;

namespace Action {
    bool attack(Room *room, Player *attacker, Player *attackee, std::string dodgeByCard);

    void recoverHealth(Player *target, int health);

}
