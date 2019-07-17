#include "..\Class Header\Deck.h"
#include "..\Constants\global.h"
#include "..\Class Header\Card.h"

Deck::Deck()
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        deck.push_back(new Card(i % NUM_RANKS, i % NUM_SUITS));
    }
}

Deck::~Deck()
{
    for (auto it = deck.begin(); it != deck.end(); ++it)
        delete *it;
    deck.clear();
}

void Deck::display() const
{
    for (auto it = deck.begin(); it != deck.end(); ++it)
        (*it)->display();
}

void Deck::shuffle()
{
    Card * temp;

    int r;

    for (int i = 0; i < NUM_CARDS; i++)
    {
        temp = deck[i];
        r = (rand() % NUM_CARDS);
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

/*
*   Determine whether the function should return a local object or a pointer.
*   How to delete/free the last element of the vector while passing the value
*   to a player or dealer.
*/
Card * Deck::pop()
{
    Card * return_card;

    (deck.size()-1 >= 0) ? return_card = deck[deck.size()-1] : return_card = NULL;

    return return_card;
}
