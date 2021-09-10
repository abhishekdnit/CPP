#include<iostream>

using namespace std;

class singleton
{
private:
     static singleton *s_instance;
     static int counter;

     singleton(){};
     singleton(const singleton &obj);

     static void addref()
     {
         counter++;
     }

     static void releasref()
     {
         counter--;
     }


public:

    static singleton* getinstance()
    {
        addref();
        if(NULL==s_instance)
        {
            cout<<"\nCreating instance ...";
            s_instance=new singleton();
        }
        return s_instance;
    }

    static singleton* releaseInstance()
    {
        releasref();
        if(0==counter && NULL!=s_instance)
        {
            cout<<"\nDeleting instance ...";
        delete s_instance;
        s_instance=NULL;
        }
        else
            cout<<"\nMultiple users using same instances so can't be deleted ...:(";
    }

};

singleton* singleton::s_instance=0;
int singleton::counter=0;

int main()
{
singleton *s_obj1=singleton::getinstance();
singleton *s_obj2=singleton::getinstance();
singleton::releaseInstance();


}
