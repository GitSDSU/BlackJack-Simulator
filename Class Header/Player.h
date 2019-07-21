#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <iostream>

class Card;

typedef std::vector< Card * > cards;

class Player
{
    public:
        Player();
        ~Player();

    protected:

    private:
        cards hand;
        std::string name;
};

#endif // PLAYER_H_INCLUDED
