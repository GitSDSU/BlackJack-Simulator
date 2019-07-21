#include "..\Class Header\Manager.h"
#include "..\Class Header\Shoe.h"
#include "..\Class Header\Dealer.h"
#include "..\Class Header\Player.h"
#include "..\Constants\global.h"
#include <ctime>

/// For testing purposes
#include <iostream>
#include "..\Class Header\Card.h"

Manager::Manager()
{
    srand(time(0));
    shoe = new Shoe;
    dealer = new Dealer;
    player = new Player;
}

Manager::~Manager()
{
    delete shoe;
    delete dealer;
    delete player;
}

void Manager::test()
{
    shoe->shuffle();
    shoe->display();

}
