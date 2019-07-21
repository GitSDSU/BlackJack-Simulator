#include "..\Class Header\Dealer.h"
#include "..\Class Header\Card.h"

Dealer::Dealer()
{
    name = "Dealer";
}

Dealer::~Dealer()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }
    hand.clear();
}

void Dealer::receive_card(Card * new_card)
{
    hand.push_back(new Card(new_card->get_rank(), new_card->get_suit()));
}

void Dealer::display_hand() const
{
    std::cout << "Dealer's Hand: \n";
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        (*it)->display();
    }
}
