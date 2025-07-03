#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(auto &elem : arr) 
    {
        cin >> elem.first;
        elem.second = 1;
    }

    for(int i = 1, size = arr.size(); i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i].first > arr[j].first)
            {
                arr[i].second = arr[j].second + 1 > arr[i].second ? arr[j].second + 1 : arr[i].second;
            }
        }
    }
    int max = 0;
    for(auto elem : arr)
        max = max > elem.second ? max : elem.second;

    cout << max << endl;
    system("pause");
    return 0;
}