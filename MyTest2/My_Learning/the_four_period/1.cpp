#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << a << " " << b << endl;
    mySwap<int>(a, b);
    cout << a << " " << b << endl;
    system("pause");
    return 0;
}