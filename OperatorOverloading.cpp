#include<iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a1):a(a1){}


    int operator +(A &a1)
    {
        return a+a1.a;
    }


};

int main()
{
A a(10),b(20);
int c=a+b;

cout<<"c = "<<c;

}
