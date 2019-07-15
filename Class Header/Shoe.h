#ifndef SHOE_H_INCLUDED
#define SHOE_H_INCLUDED

#include <vector>

class Deck;

typedef std::vector<Deck *> decks;

class Shoe
{
    public:
        Shoe();
        ~Shoe();
        void display() const;

    protected:

    private:
        decks shoe;
};

#endif // SHOE_H_INCLUDED
