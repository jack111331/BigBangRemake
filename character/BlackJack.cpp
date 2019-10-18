#include "character/BlackJack.h"
#include <string>
#include "Player.h"
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string BlackJack::name = "Black Jack";
const string BlackJack::feature = "Draw one more card from plague if the second drawed card flipped from plague is red.";

BlackJack::BlackJack(Room *room) : Character(room) {
}

const std::string &BlackJack::getName() {
    return BlackJack::name;
}

const std::string &BlackJack::getCharacterName() const {
    return BlackJack::name;
}

const std::string &BlackJack::getFeature() {
    return BlackJack::feature;
}

const std::string &BlackJack::getCharacterFeature() const {
    return BlackJack::feature;
}

int BlackJack::getMaxHp() const {
    return BlackJack::maxHp;
}

int BlackJack::getAttackRange() const {
    return BlackJack::attackRange;
}

int BlackJack::getAddAttackRange() const {
    return BlackJack::addRange;
}

int BlackJack::getDefendAttackRange() const {
    return BlackJack::defendRange;
}

bool BlackJack::isHasMultiAttack() const {
    return BlackJack::hasMultiAttack;
}

void BlackJack::drawCard(Room *room, Player *player) {
    // TODO inform flip animation
    room->drawCard(room->getPositionByPlayer(player), 1);
    Card *drawedCard = room->drawCardFromPlagueForDetermine();
    if (drawedCard->getSuit() == Suit::Heart || drawedCard->getSuit() == Suit::Diamond) {
        room->drawCard(room->getPositionByPlayer(player), 1);
    }
    player->addCardToHolding(drawedCard);
}
