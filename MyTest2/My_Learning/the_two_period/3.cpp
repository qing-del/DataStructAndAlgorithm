#include <iostream>
using namespace std;

void func(int &a)
{
    cout << "func（int &a）调用" << endl;
}

void func(const int &a)
{
    cout << "func(const int)调用" << endl;
}

int main(void)
{
    int a = 10;
    func(a); //调用第一个

    func(10);  //调用第二个
}