#include "..\Class Header\Shoe.h"
#include "..\Constants\global.h"
#include "..\Class Header\Deck.h"
#include <iostream>

Shoe::Shoe()
{
    for (int i = 0; i < NUM_DECKS; i++)
        shoe.push_back(new Deck);
}

Shoe::~Shoe()
{
    for (auto it = shoe.begin(); it != shoe.end(); ++it)
        delete (*it);
    shoe.clear();
}

void Shoe::display() const
{
    int deck_counter = 0, card_counter = 0;
    for (auto it = shoe.begin(); it != shoe.end(); ++it)
    {
        std::cout << '\n' << "Deck " << ++deck_counter << ":" << '\n';
        card_counter += (*it)->display();
    }
    std::cout << "Total # of cards in shoe: " << card_counter << '\n';
}

void Shoe::shuffle()
{
    for (auto it = shoe.begin(); it != shoe.end(); ++it)
    {
        (*it)->shuffle();
    }
}

Card * Shoe::pop()
{
    Card * return_card = NULL;

    for (int i = 0; i < (int) shoe.size(); i++)
    {
        return_card = shoe[i]->pop();

        if (return_card != NULL)
        {
            break;
        }
    }

    return return_card;
}

int Shoe::Size() const
{
    return (int) shoe.size();
}
