#pragma once

#include "Card.h"
#include "card/Winchester.h"
#include "card/Barrel.h"
#include "card/Carabine.h"
#include "card/Jail.h"
#include "card/Mustang.h"
#include "card/Remington.h"
#include "card/Saloon.h"
#include "card/Schofield.h"
#include "card/Stagecoach.h"
#include "card/Volcanic.h"
#include "card/Wellsfargo.h"
#include "card/Bang.h"
#include "card/Missed.h"
#include "card/Indians.h"
#include "card/Gatling.h"
#include "card/Duel.h"
#include "card/Beer.h"
#include "card/Panic.h"
#include "card/CatBalou.h"
#include "card/Dynamite.h"
#include "card/GeneralStore.h"
#include <string>

namespace CardGenerator {
    Card *createCard(const std::string &cardName, Room *room, int number, Suit suit);
};
