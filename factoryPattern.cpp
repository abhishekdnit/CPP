#include<iostream>

using namespace std;

enum vehicletype{two_wheel,three_wheel,four_wheel};

//Library class
class vehicle               // Abstract class
{
public:
    virtual void print()=0;
    static vehicle* factory_method(vehicletype type);   // Static member function
};
class twowheel:public vehicle
{
public:
    void print()
    {
        cout<<"Two wheeler vehicle ..."<<endl;
    }
};

class fourwheel:public vehicle
{
public:
    void print()
    {
        cout<<"Four wheeler vehicle ..."<<endl;
    }
};


vehicle* vehicle::factory_method(vehicletype type)
{
    if(type==two_wheel)
        return new twowheel();
    else if(type==four_wheel)
        return new fourwheel();
    else
        return NULL;

}

//Client class

class client
{
private:
    vehicle *pvehicle;
public:
    client(vehicletype type)
    {
        pvehicle=vehicle::factory_method(type);
    }

    ~client()
    {
        if(pvehicle)
        {
            delete[] pvehicle;
            pvehicle=NULL;
        }

    }

    vehicle* getvehicle()
    {
        return pvehicle;
    }
};

int main()
{
client *pclient=new client(two_wheel);
vehicle *pavehicle=pclient->getvehicle();
pavehicle->print();

}
