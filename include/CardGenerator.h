#pragma once
#include "Card.h"
#include <string>

namespace CardGenerator
{
  Card * createCard(const std::string &cardName, Room * room, int Number, Suit suit);
};
