#include <iostream>
using namespace std;

int runAdd(int n)
{
    if(n == 1) return 2;
    return runAdd(n - 1) + n;
}

int main()
{
    int a;
    cin >> a;
    cout << runAdd(a) << endl;
    system("pause");
    return 0;
}