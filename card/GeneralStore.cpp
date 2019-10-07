#include "card/GeneralStore.h"
#include <string>
#include "Room.h"
#include <vector>
#include "User.h"

using std::string;
using namespace BangCard;

const string GeneralStore::name = "General Store";
const string GeneralStore::feature = "Draw alive amount player card and distribute them to every player, start from yourself.";


GeneralStore::GeneralStore(Room *room, int number, Suit suit) : Card(room, number, suit) {
}

const std::string &GeneralStore::getName() {
    return GeneralStore::name;
}

const std::string &GeneralStore::getCardName() const {
    return GeneralStore::name;
}

const std::string &GeneralStore::getFeature() {
    return GeneralStore::feature;
}

const std::string &GeneralStore::getCardFeature() const {
    return GeneralStore::feature;
}

bool GeneralStore::useCardEffect(Room *room, Player *myself, Player *target) {
    if (!Card::useCardEffect(room, myself, target)) {
        return false;
    }
    size_t drawCardAmount = room->getAlivePlayerAmount();
    std::vector<Card *> chooseCardList;
    for (size_t i = 0; i < drawCardAmount; i++) {
//        Card *card;
//        if (room->GetPlague()->GetPlagueCardAmount() - i <= 0) {
//            card = room->GetPlague()->ChooseTopCard();
//        } else {
//            card = room->GetDiscardPlague()->ChooseTopCard();
//        }
//        chooseCardList.push_back(card);
    }
    for (Player *CurrentPlayer = myself;
         room->getNextPlayer(CurrentPlayer) != myself; CurrentPlayer = room->getNextPlayer(CurrentPlayer)) {
        //        CurrentPlayer->GetUser()->SendMessage("Send Message", NSWrapInfo::WrapChooseCardInfo(chooseCardList).dump());
        //        int choice = CurrentPlayer->BusyWaiting(29);
        //        for (std::vector<CCard *>::iterator it = chooseCardList.begin(); it != chooseCardList.end(); ++it) {
        //            if ((*it)->GetID() == choice) {
        //                chooseCardList.erase(it);
        //                break;
        //            }
        //        }
    }
    return true;
}
