#include "..\Class Header\Hand.h"
#include "..\Class Header\Card.h"
#include "..\Constants\global.h"

Hand::Hand()
{
    num_cards = 0;
    wager = 0;
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

void Hand::Add_Card(int rank, int suit)
{
    hand.push_back(new Card(rank, suit));
    num_cards++;
}

void Hand::Delete_Hand()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }

    hand.clear();
    wager = 0;
}

/** Assumes hand only has 2 cards since a hand can only be split before hitting **/
void Hand::Split_Hand(Hand * new_hand)
{
    new_hand->Add_Card(hand[1]->get_rank(), hand[1]->get_suit());
    delete (hand[1]);
    num_cards--;
}

/**
*   The same algorithm is used for both players & dealers.
*   Error: StringValues & CardValues mess up the algorithm.
**/
int Hand::Hand_Value()
{
    int hand_value = 0;

    int card_histogram[NUM_RANKS] = { 0 };

    /** Count the # of times each rank appears in the hand **/
    for (auto card = hand.begin(); card != hand.end(); ++card)
    {
        card_histogram[(*card)->get_rank()-1]++; /// T, J, Q, K all go in the same bin.
    }

    /** Add the values of each rank **/
    for (int i = NUM_RANKS - 1; i >= 0; i--)
    {
        if (i == (CardValues::ACE - 1))
        {
            for (int j = 0; j < card_histogram[i]; j++)
            {
                (hand_value > CardValues::TEN) ? hand_value += CardValues::ACE : hand_value += CardValues::ACE + CardValues::TEN;
            }
        }
        else if (i >= (CardValues::TEN - 1) && i <= (CardValues::KING - 1))
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

bool Hand::Is_Pair() const
{
    if (hand[0]->get_rank() == hand[1]->get_rank() && hand.size() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Hand::Has_Ace() const
{
    bool flag = false;

    if ((hand[0]->get_rank() == CardValues::ACE || hand[1]->get_rank() == CardValues::ACE) && hand.size() == 2)
    {
        if (hand[0]->get_rank() == CardValues::ACE)
        {
            int sum = 0;
            for (int i = 1; i < (int) hand.size(); i++)
            {
                sum += hand[i]->get_rank();
            }
            if (sum <= CardValues::TEN)
            {
                flag = true;
            }
        }
        else if (hand[1]->get_rank() == CardValues::ACE)
        {
            int sum = hand[0]->get_rank();
            for (int i = 2; i < (int) hand.size(); i++)
            {
                sum += hand[i]->get_rank();
            }
            if (sum <= CardValues::TEN)
            {
                flag = true;
            }
        }
        else
        {
            flag = false;
        }
    }

    return flag;
}

int Hand::First_Card() const
{
    return hand[0]->get_rank();
}

int Hand::Second_Card() const
{
    return hand[0]->get_rank();
}

bool Hand::Is_Black_Jack() const
{
    if (hand[0]->get_rank() == CardValues::ACE && hand[1]->get_rank() == CardValues::TEN)
    {
        return true;
    }
    else if (hand[0]->get_rank() == CardValues::TEN && hand[1]->get_rank() == CardValues::ACE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Hand::Double_Wager()
{
    wager *= 2;
}

void Hand::Set_Wager(int w)
{
    wager = w;
}

int Hand::Get_Wager() const
{
    return wager;
}


