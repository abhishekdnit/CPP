#include<iostream>

using namespace std;

class car
{
public:
    void run()
    {
        cout<<"We are inside running car by smart pointers\n";
    }
};

class CarSp
{
public:
    car *sp;

    CarSp(car *sptr):sp(sptr)
    {
        cout<<"Initializing smart pointer to car class object\n";
    }

    ~CarSp()
    {
        cout<<"Deallocating smart pointer ... :)\n";
        delete sp;
    }

    //overloading '->' operator
    car* operator ->()
    {
        cout<<"Overloading -> operator\n";
        return sp;
    }


};

int main()
{
    CarSp ptr(new car());   //Passing dynamic object inside constructor ...
    ptr->run();

}
