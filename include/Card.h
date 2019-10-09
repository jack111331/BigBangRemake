#pragma once

#include <string>
#include <map>
#include <vector>
#include "nlohmann/json.hpp"

class Player;

class Room;

enum class Suit {
    Spade = 0, //黑桃
    Heart, //紅心
    Diamond, //方塊
    Club //梅花
};


class Card {
public:
    Card(Room *room, int Number, Suit suit);

    virtual bool useCardEffect(Room *room, Player *myself, Player *target);

    virtual const std::string &getCardName() const = 0;

    virtual const std::string &getCardFeature() const = 0;

    virtual void handleMessage(const nlohmann::json &jsonMessage);

    int getNumber() const;

    void setNumber(int number);

    Suit getSuit() const;

    void setSuit(Suit suit);

    uint32_t getId() const;

    virtual ~Card();

protected:
    static uint32_t cardId;

private:
    int number;
    Suit suit;
    uint32_t id;

};
