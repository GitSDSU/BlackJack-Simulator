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

int Deck::display() const
{
    int card_counter = 0;
    for (auto it = deck.begin(); it != deck.end(); ++it)
    {
        card_counter++;
        (*it)->display();
    }

    return card_counter;
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

/**
*   Determine whether the function should return a local object or a pointer.
*   How to delete/free the last element of the vector while passing the value
*   to a player or dealer.
**/
/**
*   vector.size() is of type unsigned. Needs to be changed to an integer.
**/
Card * Deck::pop()
{
    Card * return_card;
    int deck_size = deck.size() - 1;

    if (deck_size >= 0)
    {
        return_card = deck[deck_size];
        deck.pop_back();
    }
    else
    {
        return_card = NULL;
    }

    return return_card;
}
