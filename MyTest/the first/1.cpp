#include <iostream>
using namespace std;

int sum(int a, int b);

int main()
{
    int a,b;
    while(cin >> a >> b)
    {
        cout << sum(a,b) << endl;
    }

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}