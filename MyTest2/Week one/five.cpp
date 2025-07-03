#include <iostream>
using namespace std;

double GetRoundSquare(double r)
{
    return 3.1415926 * r * r;
}

int main(void)
{
    int r;
    cout << "Please enter r :" << endl;
    cin >> r;
    cout << GetRoundSquare(r) << endl;
}