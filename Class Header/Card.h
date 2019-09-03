#ifndef CARD_H
#define CARD_H

class Card
{
    public:
        Card(int, int);
        Card(const Card &p2);
        ~Card();
        int get_rank() const;
        int get_suit() const;
        void display() const;

    protected:

    private:
        int rank;
        int suit;
};

#endif // CARD_H
