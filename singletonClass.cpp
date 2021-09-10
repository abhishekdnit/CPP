#include<iostream>

/*

1. Object created inside class i.e, private static pointer object.
2. Private singleton constructor & copy constructor to prevent object instantiation.
3. A public static member function which returns the singleton object & blocks user to further create object.

*/

using namespace std;

class singleton
{
    private:
    static singleton *s_instance;   // 1

    singleton()                     //2
    {
    }
    singleton(const singleton &obj){}

    public:
        static singleton* get_instance() //3
        {
            return s_instance;
        }

        void display()
        {
            cout<<"\nSingleton class!!";
        }

};

singleton* singleton::s_instance=0;

int main()
{
    singleton *s_obj1=singleton::get_instance();
    s_obj1->display();

    cout<<"\nAddress of s_obj1 = "<<s_obj1;

    singleton *s_obj2=singleton::get_instance();
    s_obj2->display();

    cout<<"\nAddress of s_obj2 = "<<s_obj2;

return 0;

}
