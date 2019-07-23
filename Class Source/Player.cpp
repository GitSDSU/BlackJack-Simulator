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
        for (auto jt = it->begin(); jt != it->end(); ++jt)
        {
            delete (*jt);
        }
    }
}
