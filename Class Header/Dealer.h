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

    protected:

    private:
        std::string name;
        cards hand;
};

#endif // DEALER_H_INCLUDED
