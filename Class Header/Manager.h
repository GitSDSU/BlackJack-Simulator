#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

class Shoe;

class Manager
{
    public:
        Manager();
        ~Manager();
        void test();

    protected:

    private:
        Shoe * shoe;
};

#endif // MANAGER_H_INCLUDED
