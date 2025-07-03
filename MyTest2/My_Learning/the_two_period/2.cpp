#include <iostream>
using namespace std;

void Test21()
{
    int a = 10;
    int &b = a;
    b = 20;
    cout << a << endl;
}

int& Test22()
{
    static int a = 10; //静态变量在全局区
    return a;
}

void Test23()
{
    int &a = Test22();

    cout << a << endl;

    Test22() = 100;  //作为左值，是引用变量

    cout << a << endl;

}
int main()
{   
    Test23();

    return 0;
}