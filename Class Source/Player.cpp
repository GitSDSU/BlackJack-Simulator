#include "..\Class Header\Player.h"
#include "..\Class Header\Card.h"
#include "..\Class Header\Hand.h"

Player::Player()
{
    name = "Player";
    hand.push_back(new Hand);
}

Player::~Player()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }
    hand.clear();
}



