#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <string>

#define DEALER_STARTING_CHIPS 100000
#define PLAYER_STARTING_CHIPS 100000
#define MIN_BET_SIZE 10

#define NUM_CARDS 52
#define NUM_DECKS 6
#define NUM_RANKS 13
#define NUM_SUITS 4
#define STAND_ON_17 17
#define SEVENTEEN 17
#define SIXTEEN 16
#define FIFTEEN 15
#define FOURTEEN 14
#define THIRTEEN 13
#define TWELVE 12
#define ELEVEN 11

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

enum Action { Hit, Stand, Split, Double };

#endif // GLOBAL_H_INCLUDED
