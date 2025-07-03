#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int day = 1;
    while(a != 1)
    {
        a = a / 2;
        day++;
    }
    cout << day << endl;
    return 0;
}