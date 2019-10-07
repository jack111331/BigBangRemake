#include "Character.h"
#include "Card.h"
#include "Plague.h"
#include "Player.h"
//#include "Action.h"
#include "Room.h"

using std::string;

uint32_t Character::characterId = 0;

Character::Character(Room *room) {
    this->id = Character::characterId++;
}

uint32_t Character::getCharacterId() {
    return characterId;
}

void Character::drawCard(Room *room, Player *player) {
    room->drawCard(room->getPositionByPlayer(player), 2);
}

uint32_t Character::getId() const {
    return id;
}
