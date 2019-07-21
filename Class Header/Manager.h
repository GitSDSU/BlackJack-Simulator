#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

class Shoe;
class Dealer;
class Player;

class Card; /// For testing purposes

class Manager
{
    public:
        Manager();
        ~Manager();
        void test();

    protected:

    private:
        Shoe * shoe;
        Dealer * dealer;
        Player * player;
};

#endif // MANAGER_H_INCLUDED
