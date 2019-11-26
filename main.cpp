#include <iostream>
#include <Network.h>
#include <LoungeManager.h>
#include <RoomManager.h>

int main() {
    LoungeManager *loungeManager = LoungeManager::getInstance();
    RoomManager *roomManager = RoomManager::getInstance();
    Network *network = Network::getInstance();
    while (1) {
    }
}