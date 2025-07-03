#include <iostream>
using namespace std;

int myAdd_1(int a, int b)
{
    return a + b;
}

template <class T>
T myAdd_2(T a, T b)
{
    return a + b;
}

int main()
{
    int a = 10;
    int b = 20;
    char c = 'a'; // a - 97

    cout << myAdd_1(a, b) << endl;
    cout << myAdd_1(a, c) << endl;
    cout << myAdd_2(a, b) << endl;
    // cout << myAdd_2(a, c) << endl;

    cout << myAdd_2<int>(a, c) << endl;

    system("pause");
    return 0;
}