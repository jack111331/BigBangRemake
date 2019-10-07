#pragma once

#include "Character.h"
#include <string>
#include <map>
#include <vector>
#include "Room.h"

namespace CharacterGenerator {
    Character *createCharacter(const std::string &characterName);
}
class RandomCharacterPool {
public:
    RandomCharacterPool();

    void removeChoiceFromPool();

    void flushChoicePool();

    const std::vector<std::string> &choiceCharacterFromPool();

private:
    std::map<std::string, bool> characterPool;
    std::vector<std::string> characterChoicePool;
};
