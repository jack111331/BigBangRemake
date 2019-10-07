#pragma once

#include "Card.h"
#include <vector>

class Plague {
public:
    void init();

    size_t getPlagueCardAmount() const;

    Card *chooseRandomCard();

    Card *chooseTopCard();

    void insertCardToPlague(Card *card);

    void removeCardFromPlague(const Card *card);

    Card *getPlagueCardById(int cardId);

    void flushPlague();

private:
    std::vector<Card *> Plague;
};
