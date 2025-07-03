#include <iostream>
using namespace std;

int * func();
void Test2();

//用new在堆区创建一个int数据的指针
int * func()
{
    return new int(10);
}

void Test2()
{
    int * arr = new int[10];

    for(int i = 0; i < 10; i++)
    {
        arr[i] = i;
        cout << arr[i] << endl;
    }
}

int main(void)
{
    int *p = func();
    cout << *p << endl;
    delete p;
    cout << *p << endl;
    Test2();
}