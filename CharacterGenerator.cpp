#include "CharacterGenerator.h"
#include "character/BartCassidy.h"
#include "character/BlackJack.h"
#include "character/SuzyLafayette.h"
#include "character/ElGringo.h"
#include "character/VultureSam.h"
#include "character/PaulRegret.h"
#include "character/RoseDoolan.h"
#include "character/WillyTheKid.h"
#include "character/GodDeveloper.h"
//#include "CharacterGenDecorator.h"
#include <string>
#include <iterator>
#include <stdlib.h>
#include "Lounge.h"

//#include "ExclusiveCardStore.h"
Character *CharacterGenerator::createCharacter(const std::string &characterName, Room *room) {
    if (characterName == "Bart Cassidy") {
        return new BangCharacter::BartCassidy(room);
    } else if (characterName == "Black Jack") {
        return new BangCharacter::BlackJack(room);
    } else if (characterName == "Suzy Lafayette") {
        return new BangCharacter::SuzyLafayette(room);
    } else if (characterName == "El Gringo") {
        return new BangCharacter::ElGringo(room);
    } else if (characterName == "Vulture Sam") {
        return new BangCharacter::VultureSam(room);
    } else if (characterName == "Paul Regret") {
        return new BangCharacter::PaulRegret(room);
    } else if (characterName == "Rose Doolan") {
        return new BangCharacter::RoseDoolan(room);
    } else if (characterName == "Willy The Kid") {
        return new BangCharacter::WillyTheKid(room);
    } else if (characterName == "God Developer") {
        return new BangCharacter::GodDeveloper(room);
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
