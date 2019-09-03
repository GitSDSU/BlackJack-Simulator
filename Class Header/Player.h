#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include <iostream>
#include <map>
#include <utility>

class Card;
class Hand;
class Shoe;

typedef std::vector< Hand * > hands;

class Player
{
    public:
        Player();
        ~Player();
        void Delete_Hand();
        void Display_Hand() const;
        void Add_Hand();
        int Check_For_Split(const int, Shoe *);
        void Wager(int);
        void Add_Chips(int);
        void Subtract_Chips(int);
        void Receive_Card(const Card *);

    protected:

    private:
        std::string name;
        hands hand;
        int chips;
};

#endif // PLAYER_H_INCLUDED
