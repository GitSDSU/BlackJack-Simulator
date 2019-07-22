#include "..\Class Header\Dealer.h"
#include "..\Class Header\Card.h"
#include "..\Constants\global.h"

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

void Dealer::Receive_Card(Card * new_card)
{
    hand.push_back(new Card(new_card->get_rank(), new_card->get_suit()));
}

void Dealer::Display_Hand() const
{
    std::cout << "Dealer's Hand: \n";
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        (*it)->display();
    }
}

int Dealer::Get_Hand_Value()
{
    int hand_value = 0;
    int card_histogram[NUM_RANKS] = { 0 };

    /** Count the # of times each rank appears in the hand **/
    for (auto card = hand.begin(); card != hand.end(); ++card)
    {
        card_histogram[(*card)->get_rank()]++;
    }
    /** Add the values of each rank **/
    for (int i = NUM_RANKS - 1; i >= 0; i--)
    {

    }

    return hand_value;
}
