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
    int rank_value = 0;

    switch (rank)
    {
        case StringValues::ACE :
            rank_value = CardValues::ACE;
            break;
        case StringValues::TWO :
            rank_value = CardValues::TWO;
            break;
        case StringValues::THREE :
            rank_value = CardValues::THREE;
            break;
        case StringValues::FOUR :
            rank_value = CardValues::FOUR;
            break;
        case StringValues::FIVE :
            rank_value = CardValues::FIVE;
            break;
        case StringValues::SIX :
            rank_value = CardValues::SIX;
            break;
        case StringValues::SEVEN :
            rank_value = CardValues::SEVEN;
            break;
        case StringValues::EIGHT :
            rank_value = CardValues::EIGHT;
            break;
        case StringValues::NINE :
            rank_value = CardValues::NINE;
            break;
        case StringValues::TEN :
            rank_value = CardValues::TEN;
            break;
        case StringValues::JACK :
            rank_value = CardValues::JACK;
            break;
        case StringValues::QUEEN :
            rank_value = CardValues::QUEEN;
            break;
        case StringValues::KING :
            rank_value = CardValues::KING;
            break;
        default :
            /** Should not get to this point. **/
            break;
    }

    return rank_value;
}

int Card::get_suit() const
{
    return suit;
}

void Card::display() const
{
    std::cout << '\t' << rank_string[rank] << " of " << suit_string[suit] << '\n' << std::flush;
}
