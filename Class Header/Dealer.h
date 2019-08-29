#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include <iostream>
#include <vector>

class Card;
class Hand;

class Dealer
{
    public:
        Dealer();
        ~Dealer();
        void Receive_Card(const Card *);
        void Display_Hand() const;
        void Reset_Hand();
        int Next_Action() const;

    protected:

    private:
        std::string name;
        Hand * hand;
};

#endif // DEALER_H_INCLUDED
