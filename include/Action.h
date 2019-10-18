#pragma once

#include <string>
#include <vo/ResistAttackResponse.h>
#include "nlohmann/json.hpp"

class Player;

class Card;

class Room;

namespace Action {
    bool attack(Room *room, Player *attacker, Player *attackee, const std::string &dodgeByCard, Response::PlayerCard::ResistAttackResponse *response);

    void lossHealth(Room *room, Player *target, Player *attacker, int health);

    void recoverHealth(Player *target, int health);
};
