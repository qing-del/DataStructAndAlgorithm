#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//t <= 2000  a < 1000   n <= 5000

vector<bool> damp(2000001, false);

int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double a;
        int t;
        cin >> a >> t;
        for(int j = 1; j <= t; j++)
        {
            int index = static_cast<int>(floor(a * j));
            if(index <= 2000000 && index >= 1) damp[index] = !damp[index];
        }
    }

    for(int i = 1; i <= 2000000; i++)
    {
        if(damp[i])
        {
            cout << i << endl; 
            break;
        }
    }
    return 0;
}