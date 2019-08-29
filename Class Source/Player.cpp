#include "..\Class Header\Player.h"
#include "..\Class Header\Card.h"
#include "..\Class Header\Hand.h"
#include <iostream>

Player::Player()
{
    name = "Player";
    hand.push_back(new Hand);
}

Player::~Player()
{
    Delete_Hand();
}

void Player::Delete_Hand()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        (*it)->Delete_Hand();
    }
    hand.clear();
}

void Player::Display_Hand() const
{
    int hand_counter = 1;

    std::cout << "Player's hand: " << '\n';

    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        std::cout << "Hand " << hand_counter++ << ": " << '\n';
        (*it)->Display_Hand();
    }
}

void Player::Add_Hand()
{
    hand.push_back(new Hand);
}

void Player::Split_Hand(const Card * first_card, const Card * second_card)
{
    Add_Hand();

    for (int i = 0; i < (int) hand.size(); i++)
    {
        if (hand[i]->Cards_In_Hand() == 0)
        {
            hand[i]->Add_Card(hand[i-1]->Split_Hand());
            hand[i-1]->Add_Card(first_card);
            hand[i]->Add_Card(second_card);
        }
    }
}



