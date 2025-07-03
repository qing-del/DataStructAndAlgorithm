#include <iostream>
using namespace std;

int F4_41(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    return F4_41(n - 1) + F4_41(n - 2) + F4_41(n - 3);
}

int main()
{
    int n;
    cin >> n;
    cout << F4_41(n) << endl;
    system("pause");
    return 0;
}