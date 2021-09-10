#include<iostream>

using namespace std;

class A
{
public:
    void fun1(){cout<<"A->fun1()\n";}
  //  void fun5(){cout<<"A->fun5()\n";}
    void virtual fun2(){cout<<"A->fun2()\n";}
    void virtual fun3(){cout<<"A->fun3()\n";}
    void virtual fun4(){cout<<"A->fun4()\n";}
};

class B:public A
{
    public:
    void fun1(){cout<<"B->fun1()\n";}
    void fun2(){cout<<"B->fun2()\n";}
    void fun4(int x){cout<<"B->fun4()\n";}
  //  void fun6(){cout<<"B->fun6()\n";}
};

int main()
{
    A *p,a;
    B b;
    p=&b;
    p->fun1();
    p->fun2();
    p->fun3();
    p->fun4();
//    p->fun4(3);

    b.fun4(9);
//    p->fun6();

}
