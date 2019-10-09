cmake_minimum_required(VERSION 3.6)
project(BigBangRemake)

set(CMAKE_CXX_STANDARD 11)

include_directories("./include")

Set(CARD_SOURCE)
Set(CARD_HEADER)

Set(CHARACTER_SOURCE)
Set(CHARACTER_HEADER)

set(SERVER_SOURCE)
set(SERVER_HEADER)

list(APPEND CARD_SOURCE
        card/Bang.cpp
        card/Barrel.cpp
        card/Beer.cpp
        card/Carabine.cpp
        card/CatBalou.cpp
        card/Duel.cpp
        card/Dynamite.cpp
        card/Gatling.cpp
        card/GeneralStore.cpp
        card/Indians.cpp
        card/Jail.cpp
        card/Missed.cpp
        card/Mustang.cpp
        card/Panic.cpp
        card/Remington.cpp
        card/Saloon.cpp
        card/Schofield.cpp
        card/Stagecoach.cpp
        card/Volcanic.cpp
        card/Wellsfargo.cpp
        card/Winchester.cpp
        )

list(APPEND CARD_HEADER
        include/card/Bang.h
        include/card/Barrel.h
        include/card/Beer.h
        include/card/Carabine.h
        include/card/CatBalou.h
        include/card/Duel.h
        include/card/Dynamite.h
        include/card/Gatling.h
        include/card/GeneralStore.h
        include/card/Indians.h
        include/card/Jail.h
        include/card/Missed.h
        include/card/Mustang.h
        include/card/Panic.h
        include/card/Remington.h
        include/card/Saloon.h
        include/card/Schofield.h
        include/card/Stagecoach.h
        include/card/Volcanic.h
        include/card/Wellsfargo.h
        include/card/Winchester.h
        )

list(APPEND CHARACTER_SOURCE
        character/BartCassidy.cpp
        character/BlackJack.cpp
        character/ElGringo.cpp
        character/GodDeveloper.cpp
        character/PaulRegret.cpp
        character/RoseDoolan.cpp
        character/SuzyLafayette.cpp
        character/VultureSam.cpp
        character/WillyTheKid.cpp
        )

list(APPEND CHARACTER_HEADER
        include/character/BartCassidy.h
        include/character/BlackJack.h
        include/character/ElGringo.h
        include/character/GodDeveloper.h
        include/character/PaulRegret.h
        include/character/RoseDoolan.h
        include/character/SuzyLafayette.h
        include/character/VultureSam.h
        include/character/WillyTheKid.h
        )


list(APPEND SERVER_SOURCE
        main.cpp
        User.cpp
        Agent.cpp
        Lounge.cpp
        LoungeManager.cpp
        Card.cpp
        CardGenerator.cpp
        EquipmentCard.cpp
        WeaponCard.cpp
        Room.cpp
        RoomManager.cpp
        Player.cpp
        Plague.cpp
        Character.cpp
        CharacterGenerator.cpp
        Network.cpp
        Action.cpp
        Equipment.cpp
        GameEventListener.cpp
        vo/ChooseCardFromAnotherPlayerRequest.cpp
        vo/ChooseCardFromAnotherPlayerResponse.cpp
        )
list(APPEND SERVER_HEADER
        include/User.h
        include/Agent.h
        include/Lounge.h
        include/LoungeManager.h
        include/Card.h
        include/CardGenerator.h
        include/EquipmentCard.h
        include/WeaponCard.h
        include/Room.h
        include/RoomManager.h
        include/Player.h
        include/Plague.h
        include/Character.h
        include/CharacterGenerator.h
        include/Network.h
        include/Action.h
        include/Equipment.h
        include/GameEventListener.h
        include/vo/
        )

set(all_code_files
        ${CARD_HEADER}
        ${CHARACTER_HEADER}
        ${SERVER_HEADER}
        ${CARD_SOURCE}
        ${CHARACTER_SOURCE}
        ${SERVER_SOURCE}
        )

add_executable(BigBangRemake ${all_code_files})
target_link_libraries(BigBangRemake boost_system ssl crypto pthread)
