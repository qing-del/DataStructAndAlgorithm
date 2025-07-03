#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int apple = 0;
    int tell;
    vector<int> highs(10);
    for(int i = 0; i < 10; i++) cin >> highs[i];
    cin >> tell;
    for(int i = 0; i < 10; i++)
    {
        if(highs[i] <= tell + 30) apple++;
    }
    cout << apple << endl;
    return 0;
}