#include <iostream>
using namespace std;

int go(int n);

int main(void)
{
    int n;
    cin >> n;
    int result = go(n);
    cout << result << endl;
}

int go(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return go(n - 1) + go(n - 2);    
}