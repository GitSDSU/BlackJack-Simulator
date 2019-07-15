#include "..\Class Header\Manager.h"
#include "..\Class Header\Shoe.h"
#include "..\Constants\global.h"

Manager::Manager()
{
    shoe = new Shoe;
}

Manager::~Manager()
{
    delete shoe;
}
