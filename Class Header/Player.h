#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <iostream>

class Card;

/** Use a two-dimensional vector to support splitting **/
typedef std::vector< Card * > PartialHand;
typedef std::vector< PartialHand > EntireHand;

class Player
{
    public:
        Player();
        ~Player();

    protected:

    private:
        EntireHand hand;
        std::string name;
};

#endif // PLAYER_H_INCLUDED
