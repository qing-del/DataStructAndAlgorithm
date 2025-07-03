#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &num : arr) cin >> num;
    vector<int> record(n, 1);
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i + 1] == arr[i] + 1) record[i + 1] = record[i] + 1;
    }
    int max = record[0];
    for(auto elem : record) max = max > elem ? max : elem;
    cout << max << endl;
    return 0;
}