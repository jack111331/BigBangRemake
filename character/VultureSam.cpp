#include "character/VultureSam.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Room.h"

using std::string;
using namespace BangCharacter;

const string VultureSam::name = "Vulture Sam";
const string VultureSam::feature = "When a player is dead, pick up all his holding.";

VultureSam::VultureSam(Room *room) : Character(room) {
    this->listener = new GameEventListener();
    listener->onLossBlood = std::bind(&VultureSam::onDeath, this, std::placeholders::_1, std::placeholders::_2,
                                      std::placeholders::_3);
    room->getEventListener()->subscribe(listener);
}

const std::string &VultureSam::getName() {
    return VultureSam::name;
}

const std::string &VultureSam::getCharacterName() const {
    return VultureSam::name;
}

const std::string &VultureSam::getFeature() {
    return VultureSam::feature;
}

const std::string &VultureSam::getCharacterFeature() const {
    return VultureSam::feature;
}

int VultureSam::getMaxHp() const {
    return VultureSam::maxHp;
}

int VultureSam::getAttackRange() const {
    return VultureSam::attackRange;
}

int VultureSam::getAddRange() const {
    return VultureSam::addRange;
}

int VultureSam::getDefendRange() const {
    return VultureSam::defendRange;
}

bool VultureSam::isHasMultiAttack() const {
    return VultureSam::hasMultiAttack;
}

void VultureSam::onDeath(Room *room, Player *deadPerson, Player *attacker) {
    auto playerList = room->getPlayerList();
    for (auto player : playerList) {
        if (player->getCharacter()->getCharacterName() == VultureSam::getName()) {
            auto holdingList = deadPerson->getHolding();
            for (auto holding : holdingList) {
                room->giveCard(holding->getId(), room->getPositionByPlayer(deadPerson),
                               room->getPositionByPlayer(player));
            }
            break;
        }
    }
}

VultureSam::~VultureSam() {
    // TODO destroy listener
}