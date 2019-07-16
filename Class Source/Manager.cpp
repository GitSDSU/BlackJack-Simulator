#include "..\Class Header\Manager.h"
#include "..\Class Header\Shoe.h"
#include "..\Constants\global.h"
#include <ctime>

Manager::Manager()
{
    srand(time(0));
    shoe = new Shoe;
}

Manager::~Manager()
{
    delete shoe;
}

void Manager::test()
{
    shoe->shuffle();
    shoe->display();
}
