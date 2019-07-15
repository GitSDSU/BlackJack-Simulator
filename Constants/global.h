#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <string>

#define NUM_CARDS 52
#define NUM_DECKS 6
#define NUM_RANKS 13
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

const std::string rank_string[] =
{
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const std::string suit_string[] =
{
    "Spade", "Heart", "Clove", "Diamond"
};

#endif // GLOBAL_H_INCLUDED
