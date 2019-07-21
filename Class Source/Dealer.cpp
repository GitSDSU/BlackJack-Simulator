#include "..\Class Header\Dealer.h"
#include "..\Class Header\Card.h"

Dealer::Dealer()
{

}

Dealer::~Dealer()
{
    for (auto it = hand.begin(); it != hand.end(); ++it)
    {
        delete (*it);
    }
    hand.clear();
}
