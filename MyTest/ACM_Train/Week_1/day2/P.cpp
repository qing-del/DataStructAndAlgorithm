#include <iostream>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;
    int count = x;
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        if(count < 6) s += 250;
        if(count == 7)
        {
            count = 0;
        }
        count++;
    }
    cout << s << endl;
    return 0;
}