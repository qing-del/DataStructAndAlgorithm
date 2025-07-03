#include <iostream>
using namespace std;

int SearchMax(int a,int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int a , b;
    cin >> a >> b;
    cout << SearchMax(a,b) << endl;
}