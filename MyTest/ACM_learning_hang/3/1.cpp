//航电算法入门 例题二：
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pay
{
    int u;
    int v;
    int w; //费用
};

bool compare(const pay& a, const pay& b)
{
    return a.w < b.w;
}

void load(int n, vector<int> &arr)
{
    for(int i = 0; i < n; i++) arr[i] = i; 
}

int findx(vector<int> &arr, const int &x)
{
    if(arr[x] != x)
        arr[x] = findx(arr, arr[x]);
    return arr[x];
}

int main()
{
    int n, m, u, v, w, sum = 0, count = 0;
    cin >> n >> m;
    vector<pay> arr(m);
    vector<int> city(n + 1);
    load(n + 1, city);
    for(auto &elem : arr)
        cin >> elem.u >> elem.v >> elem.w;
    sort(arr.begin(), arr.end(), compare); //按照费用排序
    for(int i = 0; i < m; i++)
    {
        if(findx(city, arr[i].u) != findx(city, arr[i].v))
        {
            sum += arr[i].w;
            count++;
        }
        if(count == n - 1) break;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}