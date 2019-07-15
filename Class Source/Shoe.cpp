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
    int i = 1;
    for (auto it = shoe.begin(); it != shoe.end(); ++it)
    {
        std::cout << "Deck " << i++ << ":" << '\n';
        (*it)->display();
    }
}
