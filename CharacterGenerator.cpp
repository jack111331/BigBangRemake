#include "CharacterGenerator.h"
//#include "BartCassidy.h"
//#include "BlackJack.h"
//#include "SuzyLafayette.h"
//#include "ElGringo.h"
//#include "VultureSam.h"
//#include "PaulRegret.h"
//#include "RoseDoolan.h"
//#include "WillyTheKid.h"
//#include "GodDeveloper.h"
//#include "CharacterGenDecorator.h"
#include <string>
#include <iterator>
#include <stdlib.h>
#include "Lounge.h"

//#include "ExclusiveCardStore.h"
Character *CharacterGenerator::createCharacter(const std::string &characterName) {
    if (characterName == "Bart Cassidy") {
//        return new CCharacterBart(room);
    } else if (characterName == "Black Jack") {
//        return new BlackJack(room);
    } else if (characterName == "Suzy Lafayette") {
//        return new CCharacterLafayette(room);
    } else if (characterName == "El Gringo") {
//        return new CCharacterGringo(room);
    } else if (characterName == "Vulture Sam") {
//        return new CCharacterSam(room);
    } else if (characterName == "Paul Regret") {
//        return new CCharacterPaul(room);
    } else if (characterName == "Rose Doolan") {
//        return new CCharacterRose(room);
    } else if (characterName == "Willy The Kid") {
//        return new CCharacterWilly(room);
    } else if (characterName == "God Developer") {
//        return new CCharacterGod(room);
    } else {
        return nullptr;
    }
}

RandomCharacterPool::RandomCharacterPool() {
    //init character deck
//    CCharacterGenComponent *CharacterComponent = new CCharacterGenConcreteComponent();
//    if (room->GetLounge()->getEnableExclusiveCard()) {
//        std::map<uint32_t, bool> CharacterCardSet;
//        for (std::vector<CPlayer *>::iterator it = room->GetPlayerList().begin();
//             it != room->GetPlayerList().end(); ++it) {
//            std::vector<uint32_t> CardList = (*it)->GetUser()->GetExclusiveCardInventory()->GetCharacterCardList();
//            for (int i = 0; i < static_cast<int>(CardList.size()); ++i) {
//                CharacterCardSet[CardList[i]] = 1;
//            }
//        }
//        CharacterComponent = CExclusiveCardStore::GetInstance()->GenerateExclusiveCharacter(CharacterCardSet,
//                                                                                            CharacterComponent);
//    }
//    characterPool = CharacterComponent->GetGenerateCharacter();
    //.....
}

void RandomCharacterPool::removeChoiceFromPool() {
    for (auto it = characterChoicePool.begin(); it != characterChoicePool.end(); ++it) {
        characterPool.erase(*it);
    }
    characterChoicePool.clear();
}

void RandomCharacterPool::flushChoicePool() {
    constexpr int choiceAmount = 2;
//    srand(time(NULL));
    for (size_t i = characterChoicePool.size(); i < choiceAmount; ++i) {
        auto it = characterPool.begin();
        std::advance(it, rand() % characterPool.size());
        characterChoicePool.push_back(it->first);
        characterPool.erase(it);
    }
}

const std::vector<std::string> &RandomCharacterPool::choiceCharacterFromPool() {
    return characterChoicePool;
}
