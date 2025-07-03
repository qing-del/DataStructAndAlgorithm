#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j != 0)
        {
            if(j % 10 == x) count++;
            j = j / 10;
        }
    }
    cout << count << endl;
    return 0;
}