#include <iostream>
using namespace std;

int main()
{
    int m, t, s;
    cin >> m >> t >> s;
    if(t == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int eat = s / t;
    if(s % t != 0) eat++;
    if(m - eat < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << m - eat << endl;
    return 0;
}