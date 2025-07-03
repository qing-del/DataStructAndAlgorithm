#include <iostream>
using namespace std;

unsigned long P1634_01(const unsigned long &x, const unsigned long &n)
{
    if (n == 0)
        return 1;
    return P1634_01(x, n - 1) * (x + 1);
}

int main()
{
    unsigned long x, n;
    cin >> x >> n;
    cout << P1634_01(x, n) << endl;
    system("pause");
    return 0;
}