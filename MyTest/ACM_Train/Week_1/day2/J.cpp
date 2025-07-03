#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> peoples(4, 0);
    if(x % 2 == 0 && (x > 4 && x <= 12))
    {
        peoples[0] = 1;
        peoples[1] = 1;
    } else if (x % 2 == 0 || (x > 4 && x <= 12))
    {
        peoples[1] = 1;
        peoples[2] = 1;
    } else 
    {
        peoples[3] = 1;
    }

    for(auto num : peoples)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}