#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int self, team;
    self = 5 * n;
    team = 3 * n + 11;
    if(self < team)
    {
        cout << "Local" << endl;
    } else 
    {
        cout << "Luogu" << endl;
    }
    return 0;
}