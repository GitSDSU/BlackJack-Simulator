#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define NUM_CARDS 52
#define NUM_DECKS 6
#define NUM_SUITS 4

namespace StringValues
{
    enum { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum { SPADE, HEART, CLOVE, DIAMOND };
}

namespace CardValues
{
    enum { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
}

#endif // GLOBAL_H_INCLUDED
