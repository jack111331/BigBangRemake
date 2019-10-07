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

void Plague::init() {
    //    CCardGenComponent *CardComponent = new CCardGenConcreteComponent(room);
    //    if (room->GetLounge()->getEnableExclusiveCard()) {
    //        // get all player's exclusive card
    //        std::map<uint32_t, bool> EffectAndEquipmentCardSet;
    //        for (std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();
    //             it != room->GetPlayerList().end(); ++it) {
    //            std::vector<uint32_t> CardList = (*it)->GetUser()->GetExclusiveCardInventory()->GetEffectAndEquipmentCardList();
    //            for (int i = 0; i < static_cast<int>(CardList.size()); ++i) {
    //                EffectAndEquipmentCardSet[CardList[i]] = 1;
    //            }
    //        }
    //        CardComponent = CExclusiveCardStore::GetInstance()->GenerateExclusiveCard(EffectAndEquipmentCardSet,
    //                                                                                  CardComponent, room);
    //    }
    //    Plague = CardComponent->GetGeneratePlague();
    //    srand(time(0));
    //    std::random_shuffle(Plague.begin(), Plague.end());
}

size_t Plague::getPlagueCardAmount() const {
    return Plague.size();
}

Card *Plague::chooseRandomCard() {
    srand(time(0));
    int PlagueCardAmount = getPlagueCardAmount();
    if (PlagueCardAmount) {
        int random = rand() % PlagueCardAmount;
        return Plague[random];
    } else {
        return nullptr;
    }
}

Card *Plague::chooseTopCard() {
    return Plague.at(Plague.size() - 1);
}

void Plague::insertCardToPlague(Card *card) {
    Plague.push_back(card);
}

void Plague::removeCardFromPlague(const Card *card) {
    for (size_t i = 0; i < Plague.size(); ++i) {
        if (Plague[i] == card) {
            Plague.erase(Plague.begin() + i);
            break;
        }
    }
}

Card *Plague::getPlagueCardById(int cardId) {
    for (auto card : Plague) {
        if (card->getId() == cardId) {
            return card;
        }
    }
    return nullptr;
}

void Plague::flushPlague() {
    std::shuffle(Plague.begin(), Plague.end(), std::mt19937(std::random_device()()));
}
