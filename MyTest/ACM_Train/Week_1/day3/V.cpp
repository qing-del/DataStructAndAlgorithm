#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i;j ++)
        {
            if(count < 10) cout << 0;
            cout << count++;
        }
        cout << endl;
    }
    return 0;
}