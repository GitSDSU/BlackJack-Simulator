#include "..\Class Header\Player.h"
#include "..\Class Header\Card.h"

Player::Player()
{
    name = "Player";
}

Player::~Player()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }
    hand.clear();
}
