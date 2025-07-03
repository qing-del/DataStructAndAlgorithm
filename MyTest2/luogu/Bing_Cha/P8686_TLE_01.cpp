#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for(auto &elem : arr)
        cin >> elem;
    
    for(int i = 1; i < N; i++)
    {
        while(count(arr.begin(), arr.begin() + i, arr[i]) > 0)
        {
            arr[i]++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}