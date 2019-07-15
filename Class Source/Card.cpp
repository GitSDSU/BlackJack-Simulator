#include "..\Class Header\Card.h"
#include "..\Constants\global.h"
#include <iostream>
#include <assert.h>

Card::Card(int r, int s)
{
    assert(r < NUM_RANKS);
    assert(s < NUM_SUITS);
    rank = r;
    suit = s;
}

Card::~Card()
{
    //dtor
}

int Card::get_rank() const
{
    return rank;
}

int Card::get_suit() const
{
    return suit;
}

void Card::display() const
{
    std::cout << rank_string[rank] << " of " << suit_string[suit] << '\n';
}
