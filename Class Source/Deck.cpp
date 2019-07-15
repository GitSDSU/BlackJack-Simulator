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
