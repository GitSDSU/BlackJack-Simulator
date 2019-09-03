#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <vector>

class Card;

typedef std::vector< Card * > cards;

class Hand
{
    public:
        Hand();
        ~Hand();
        void Add_Card(const Card *);
        void Delete_Hand();
        Card * Split_Hand();
        int Hand_Value();
        void Display_Hand() const;
        int Cards_In_Hand() const;
        bool Is_Pair() const;
        bool Has_Ace() const;
        int First_Card() const;
        int Second_Card() const;
        bool Is_Black_Jack() const;
        void Double_Wager();
        void Set_Wager(int);
        int Get_Wager() const;

    protected:

    private:
        cards hand;
        int num_cards;
        int wager;
};

#endif // HAND_H_INCLUDED
