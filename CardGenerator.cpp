#include "CardGenerator.h"
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

using namespace CardGenerator;
using namespace BangCard;

Card *createCard(const std::string &cardName, Room *room, int number, Suit suit) {
    if (cardName == Bang::getName()) {
        return new Bang(room, number, suit);
    } else if (cardName == Barrel::getName()) {
        return new Barrel(room, number, suit);
    } else if (cardName == Beer::getName()) {
        return new Beer(room, number, suit);
    } else if (cardName == Carabine::getName()) {
        return new Carabine(room, number, suit);
    } else if (cardName == CatBalou::getName()) {
        return new CatBalou(room, number, suit);
    } else if (cardName == Duel::getName()) {
        return new Duel(room, number, suit);
    } else if (cardName == Dynamite::getName()) {
        return new Dynamite(room, number, suit);
    } else if (cardName == Gatling::getName()) {
        return new Gatling(room, number, suit);
    } else if (cardName == GeneralStore::getName()) {
        return new GeneralStore(room, number, suit);
    } else if (cardName == Indians::getName()) {
        return new Indians(room, number, suit);
    } else if (cardName == Jail::getName()) {
        return new Jail(room, number, suit);
    } else if (cardName == Missed::getName()) {
        return new Missed(room, number, suit);
    } else if (cardName == Mustang::getName()) {
        return new Mustang(room, number, suit);
    } else if (cardName == Panic::getName()) {
        return new Panic(room, number, suit);
    } else if (cardName == Remington::getName()) {
        return new Remington(room, number, suit);
    } else if (cardName == Saloon::getName()) {
        return new Saloon(room, number, suit);
    } else if (cardName == Schofield::getName()) {
        return new Schofield(room, number, suit);
    } else if (cardName == Stagecoach::getName()) {
        return new Stagecoach(room, number, suit);
    } else if (cardName == Volcanic::getName()) {
        return new Volcanic(room, number, suit);
    } else if (cardName == Wellsfargo::getName()) {
        return new Wellsfargo(room, number, suit);
    } else if (cardName == Winchester::getName()) {
        return new Winchester(room, number, suit);
    } else {
        return nullptr;
    }
}
