#include <iostream>
using namespace std;

int main()
{
    int n, min;
    cin >> n >> min;
    for(int i = 1; i < n; i++) 
    {
        int input;
        cin >> input;
        min = min < input ? min : input;
    }
    cout << min << endl;
    return 0;
}