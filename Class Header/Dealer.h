#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include <iostream>
#include <vector>

class Card;
class Hand;
class Shoe;

class Dealer
{
    public:
        Dealer();
        ~Dealer();
        void Receive_Card(const Card *);
        void Display_Hand() const;
        void Reset_Hand();
        int Next_Action() const;
        void Add_Chips(int);
        void Subtract_Chips(int);
        int Face_Up_Card() const;
        void Dealer_To_Act(Shoe *);
        int Get_Hand_Value() const;
        bool Has_Black_Jack() const;

    protected:

    private:
        std::string name;
        Hand * hand;
        int chips;
};

#endif // DEALER_H_INCLUDED
