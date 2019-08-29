#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <iostream>

class Card;
class Hand;

typedef std::vector< Hand * > hands;

class Player
{
    public:
        Player();
        ~Player();
        void Delete_Hand();
        void Display_Hand() const;
        void Add_Hand();
        void Split_Hand(const Card *, const Card *);

    protected:

    private:
        std::string name;
        hands hand;
};

#endif // PLAYER_H_INCLUDED
