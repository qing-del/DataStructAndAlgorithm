//正整数合集  数不相同   有多少个数 == 一个合集中两数之和
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &elem : arr) cin >> elem;
    sort(arr.begin(), arr.end());
    vector<bool> exist(arr[n - 1] + 1, false);  //记得做边界判定
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] <= arr[n - 1])
            {
                exist[arr[i] + arr[j]] = true;
            } else
            {
                break;
            }
        }
    }
    int count = 0; //计数器
    for(int i = 0; i < n; i++) 
    {
        if(exist[arr[i]]) count++;
    }
    cout << count << endl;
    system("pause");
    return 0;
}