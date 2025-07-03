#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    vector<int> arr(3);
    for(auto &elem : arr) cin >> elem;
    cin >> input;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < 3; i++)
    {
        if(input[i] == 'A')
        {
            cout << arr[0] << " ";
        } else if(input[i] == 'B')
        {
            cout << arr[1] << " ";
        } else
        {
            cout << arr[2] << " ";
        }
    }
    cout << endl;

    return 0;
}