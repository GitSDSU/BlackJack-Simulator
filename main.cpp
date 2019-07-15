#include <iostream>
#include "Constants\global.h"
#include "Class Header\Shoe.h"
#include <ctime>

int main()
{
    srand(time(0));

    Shoe shoe;
    shoe.shuffle();
    shoe.display();

    return 0;
}
