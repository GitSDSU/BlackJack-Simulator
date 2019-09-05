#ifndef SHOE_H_INCLUDED
#define SHOE_H_INCLUDED

#include <vector>

class Card;
class Deck;

typedef std::vector<Deck *> decks;

class Shoe
{
    public:
        Shoe();
        ~Shoe();
        void display() const;
        void shuffle();
        Card * pop();
        int Size() const;

    protected:

    private:
        decks shoe;
};

#endif // SHOE_H_INCLUDED
