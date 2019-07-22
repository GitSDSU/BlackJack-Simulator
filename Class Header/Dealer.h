#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include <iostream>
#include <vector>

class Card;

typedef std::vector< Card * > cards;

class Dealer
{
    public:
        Dealer();
        ~Dealer();
        void Receive_Card(Card *);
        void Display_Hand() const;
        int Get_Hand_Value();

    protected:

    private:
        std::string name;
        cards hand;
};

#endif // DEALER_H_INCLUDED
