#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <vector>

class Card;

typedef std::vector<Card *> cards;

class Deck
{
    public:
        Deck();
        ~Deck();
        void display() const;
        void shuffle();

    protected:

    private:
        cards deck;
};

#endif // DECK_H_INCLUDED
