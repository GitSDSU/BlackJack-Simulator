#include "..\Class Header\Dealer.h"
#include "..\Class Header\Card.h"
#include "..\Class Header\Hand.h"
#include "..\Constants\global.h"

Dealer::Dealer()
{
    name = "Dealer";
    hand = new Hand;
}

Dealer::~Dealer()
{
    delete hand;
}

void Dealer::Receive_Card(const Card * new_card)
{
    hand->Add_Card(new_card);
}

void Dealer::Display_Hand() const
{
    std::cout << "Dealer's Hand: \n";
    hand->Display_Hand();
}

void Dealer::Reset_Hand()
{
    hand->Delete_Hand();
}

int Dealer::Next_Action() const
{
    int action;

    (hand->Hand_Value() >= STAND_ON_17) ? action = Action::Stand : action = Action::Hit;

    return action;
}

