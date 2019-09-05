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
    long int counter = 1;

    while (counter <= NUM_HANDS)
    {
        dealer->Receive_Card(shoe->pop());
        player->Receive_Card(shoe->pop());
        player->Receive_Card(shoe->pop());

        //dealer->Display_Hand();
        //player->Display_Hand();

        player->Check_For_Split(dealer->Face_Up_Card(), shoe);
        dealer->Dealer_To_Act(shoe);
        player->Wager(MIN_BET_SIZE);
        player->Compare_Hands(dealer);

        //player->Display_Hand();
        //dealer->Display_Hand();

        player->Delete_Hand();
        dealer->Reset_Hand();

        if ((int) shoe->Size() < (NUM_DECKS - 1))
        {
            delete shoe;
            shoe = new Shoe;
            shoe->shuffle();
        }
        counter++;
    }
    player->Display_Hand();
    dealer->Display_Hand();
}
