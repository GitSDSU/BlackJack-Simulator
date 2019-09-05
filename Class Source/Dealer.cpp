#include "..\Class Header\Dealer.h"
#include "..\Class Header\Card.h"
#include "..\Class Header\Hand.h"
#include "..\Class Header\Shoe.h"
#include "..\Constants\global.h"

Dealer::Dealer()
{
    name = "Dealer";
    hand = new Hand;
    chips = DEALER_STARTING_CHIPS;
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
    std::cout << "Dealer: " << '\n';
    std::cout << '\t' << "Chips = " << chips << '\n';
    std::cout << '\t' << "Value = " << hand->Hand_Value() << '\n';
    hand->Display_Hand();
    std::cout << '\n';
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

void Dealer::Add_Chips(int c)
{
    chips += c;
}

void Dealer::Subtract_Chips(int c)
{
    chips -= c;
}

int Dealer::Face_Up_Card() const
{
    return hand->First_Card();
}

/** Assume dealer has only one card. **/
void Dealer::Dealer_To_Act(Shoe * shoe)
{
    Receive_Card(shoe->pop());

    while (Next_Action() != Action::Stand)
    {
        Receive_Card(shoe->pop());
    }
}

int Dealer::Get_Hand_Value() const
{
    return hand->Hand_Value();
}

bool Dealer::Has_Black_Jack() const
{
    return hand->Is_Black_Jack();
}


