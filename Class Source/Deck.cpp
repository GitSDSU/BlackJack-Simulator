#include "..\Class Header\Deck.h"
#include "..\Constants\global.h"
#include "..\Class Header\Card.h"

Deck::Deck()
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        deck.push_back(new Card(i % NUM_RANKS, i % NUM_SUITS));
    }

    deck_counter = 0;
}

Deck::~Deck()
{
    for (auto it = deck.begin(); it != deck.end(); ++it)
    {
        delete *it;
    }
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

/**
*   Reorders deck & resets deck_counter
**/
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

    deck_counter = 0;
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
    Card * return_card = NULL;

    if (deck_counter < (int) deck.size())
    {
        return_card = deck[deck_counter];
        deck_counter++;
    }

    return return_card;
}

int Deck::Size() const
{
    return (int) deck.size();
}
