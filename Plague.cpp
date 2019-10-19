#include "Plague.h"
#include <time.h>
#include <algorithm>
#include "Room.h"
#include "Lounge.h"
#include <map>
#include <random>
//#include "CardGenFactory.h"
//#include "CardGenDecorator.h"
//#include "ExclusiveCardStore.h"

void Plague::init(std::vector<Card *> initCardList) {
    this->plague = initCardList;
}

size_t Plague::getPlagueCardAmount() const {
    return plague.size();
}

Card *Plague::chooseRandomCard() {
    srand(time(0));
    int PlagueCardAmount = getPlagueCardAmount();
    if (PlagueCardAmount) {
        int random = rand() % PlagueCardAmount;
        return plague[random];
    } else {
        return nullptr;
    }
}

Card *Plague::chooseTopCard() {
    return plague.at(plague.size() - 1);
}

void Plague::insertCardToPlague(Card *card) {
    plague.push_back(card);
}

void Plague::removeCardFromPlague(const Card *card) {
    for (size_t i = 0; i < plague.size(); ++i) {
        if (plague[i] == card) {
            plague.erase(plague.begin() + i);
            break;
        }
    }
}

Card *Plague::getPlagueCardById(int cardId) {
    for (auto card : plague) {
        if (card->getId() == cardId) {
            return card;
        }
    }
    return nullptr;
}

void Plague::flushPlague() {
    std::shuffle(plague.begin(), plague.end(), std::mt19937(std::random_device()()));
}
