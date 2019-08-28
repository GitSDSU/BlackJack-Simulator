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

    protected:

    private:
        cards hand;
};

#endif // HAND_H_INCLUDED
