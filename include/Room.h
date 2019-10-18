#pragma once

#include "Plague.h"
#include "Player.h"
#include "Agent.h"
#include "GameEventListener.h"
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>

typedef size_t position;

class User;

// TODO add more state to describe game
enum class RoomState {
    WaitPlayerToChooseCharacter,
    PlayerCompleteChoosedCharacter,
    StartGame,
    WaitPlayerToUseCard,
    PlayerCompleteUsedCard,
    WaitPlayerToFoldCard,
    PlayerCompleteFoldedCard
};

enum class WinCondition {
    SergeantWin, //警長
    BadAssWin, //副警長
    TraitorWin, //歹徒
    None
};

class Room {
public:
    Room();

    // Player Related
    bool drawCard(position drawerPosition, size_t amount);

    bool useCard(uint32_t cardId, position userPosition, position targetPosition);

    bool foldCard(uint32_t cardId, position folderPosition);

    bool giveCard(uint32_t cardId, position giverPosition, position receiverPosition);

    Card *drawCardFromPlagueForDetermine(); // TODO name should be refactor to be more general

    void putDetermineCardIntoPlague(Card *card);

    // Room Related
    void changeRoomState(RoomState roomState);

    void flushPlague();

    void playerJoin(Agent *agent);

    void loopToCheckHaveCharacter();

    WinCondition isGameEnd();

    void initPlayerState();

    void resetPlayerRoundState(Player *player);

    int getDistance(Player *watcher, Player *watchee);

    size_t getAlivePlayerAmount();

    const std::vector<Player *> &getPlayerList() const;

    size_t getPlayerAmount();

    Player *getNextPlayer(Player *currentPlayer);

    Player *getPlayerByPosition(size_t position);

    position getPositionByPlayer(Player *targetPlayer);

    bool isPlayerTurn(Player *player);

    EventSubject *getEventListener() const;

    void updatePlayerPublicInfo();

    ~Room();

private:
    void autoChooseIdentity();

    void sleepUntil(RoomState roomState);

    void startGame();

    void initGame();

    void endGame(WinCondition endGameState);

    void gameLoop();

    RoomState roomState;

    Plague *plague;
    Plague *discardPlague;
    std::vector<Player *> playerList;
    Player *currentPlayer;
    EventSubject *eventListener;

    // thread administration
    std::thread gameThread;
    std::condition_variable conditionVariable;
    std::mutex mutex;

};
