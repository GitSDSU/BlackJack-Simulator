#include "..\Class Header\Hand.h"
#include "..\Class Header\Card.h"
#include "..\Constants\global.h"

Hand::Hand()
{
    num_cards = 0;
}

Hand::~Hand()
{
    Delete_Hand();
}

void Hand::Add_Card(const Card * new_card)
{
    hand.push_back(new Card(new_card->get_rank(), new_card->get_suit()));
    num_cards++;
}

void Hand::Delete_Hand()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }

    hand.clear();
}

/** Assumes hand only has 2 cards since a hand can only be split before hitting **/
Card * Hand::Split_Hand()
{
    Card * temp;
    temp = hand[1];
    hand.pop_back();
    num_cards--;

    return temp;
}

/** The same algorithm is used for both players & dealers **/
int Hand::Hand_Value()
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
        if (i == StringValues::ACE)
        {
            for (int j = 0; j < card_histogram[i]; j++)
            {
                (hand_value > CardValues::TEN) ? hand_value += CardValues::ACE : hand_value += CardValues::ACE + CardValues::TEN;
            }
        }
        else if (i >= StringValues::TEN && i <= StringValues::KING)
        {
            hand_value += (CardValues::TEN * card_histogram[i]);
        }
        else
        {
            hand_value += ((i + 1) * card_histogram[i]);
        }
    }

    return hand_value;
}

void Hand::Display_Hand() const
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        (*it)->display();
    }
}

int Hand::Cards_In_Hand() const
{
    return num_cards;
}



