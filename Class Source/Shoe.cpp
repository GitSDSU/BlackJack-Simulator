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
        (*it)->shuffle();
}

Card * Shoe::pop()
{
    Card * return_card = NULL;

    int i = NUM_DECKS - 1;

    while (return_card == NULL)
    {
        return_card = shoe[i]->pop();
        i--;
        if (i < 0 && return_card == NULL)
        {
            std::cout << "Ran out of cards... \n";
            break;
        }
    }

    return return_card;
}
