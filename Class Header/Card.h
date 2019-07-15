#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
    public:
        Card(int, int);
        ~Card();

    protected:

    private:
        int rank;
        int suit;
};

#endif // CARD_H
