#include "..\Class Header\Card.h"
#include "..\Constants\global.h"
#include <iostream>
#include <assert.h>

Card::Card(int r, int s)
{
    assert(r < NUM_RANKS);
    assert(s < NUM_SUITS);

    switch (r)
    {
        case StringValues::ACE :
            rank = CardValues::ACE;
            break;
        case StringValues::TWO :
            rank = CardValues::TWO;
            break;
        case StringValues::THREE :
            rank = CardValues::THREE;
            break;
        case StringValues::FOUR :
            rank = CardValues::FOUR;
            break;
        case StringValues::FIVE :
            rank = CardValues::FIVE;
            break;
        case StringValues::SIX :
            rank = CardValues::SIX;
            break;
        case StringValues::SEVEN :
            rank = CardValues::SEVEN;
            break;
        case StringValues::EIGHT :
            rank = CardValues::EIGHT;
            break;
        case StringValues::NINE :
            rank = CardValues::NINE;
            break;
        case StringValues::TEN :
            rank = CardValues::TEN;
            break;
        case StringValues::JACK :
            rank = CardValues::JACK;
            break;
        case StringValues::QUEEN :
            rank = CardValues::QUEEN;
            break;
        case StringValues::KING :
            rank = CardValues::KING;
            break;
    }
    rank = r;
    suit = s;
}

Card::Card(const Card & new_card)
{
    rank = new_card.rank;
    suit = new_card.suit;
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
    std::cout << rank_string[rank] << " of " << suit_string[suit] << '\n' << std::flush;
}
