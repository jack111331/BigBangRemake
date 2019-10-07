#include "card/CatBalou.h"
#include <string>
#include "Room.h"
#include "Action.h"
//#include "DrawCardFactory.h"
#include "User.h"
//#include "WrapInfo.h"

using std::string;
using namespace BangCard;

const string CatBalou::name = "Cat Balou";
const string CatBalou::feature = "Discard one card from one player.";


CatBalou::CatBalou(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &CatBalou::getName() {
    return CatBalou::name;
}

const std::string &CatBalou::getCardName() const {
    return CatBalou::name;
}

const std::string &CatBalou::getFeature() {
    return CatBalou::feature;
}

const std::string &CatBalou::getCardFeature() const {
    return CatBalou::feature;
}

bool CatBalou::useCardEffect(Room *room, Player *myself, Player *target) {
    if(!Card::useCardEffect(room, myself, target)) {
        return false;
    }
//    myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
//    target->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapShowCard(myself, target).dump());
//    myself->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCard(myself, target, false).dump());
//    myself->BusyWaiting(11);
    return true;
}
