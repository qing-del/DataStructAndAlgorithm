#include <iostream>
using namespace std;

class Person
{
public:
    Person(){}

    Person(int age)
    {
        this->age = age;
    }

    ~Person(){}

    void showClass()
    {
        cout << "this is Person class" << endl;
    }

    void showAge()
    {
        if (this == NULL) //健壮性逻辑
        {
            return;
        }
        
        cout << this->age << endl;
    }

    int age;
}

void Test61()
{
    Person * p = NULL;
    p->showClass(); //这个调用成立
    p->showAge(); //这个调用会导致程序崩溃 使代码富有健壮性
}

int main()
{
    Test61();
    return 0;
}