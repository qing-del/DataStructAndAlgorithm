#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> set;

int main()
{
    int n, m;
    cin >> n >> m;
    set.resize(n + 1, 0); //采取了 下标对值的储存方式；
    set[1] = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        set[b] = a;
    }

    for (int i = 0; i < m; i++)
    {
        vector<int> arr1;
        vector<int> arr2;
        int a, b;
        cin >> a >> b;
        arr1.push_back(a);
        arr2.push_back(b);
        while (set[a] != a)
        {
            a = set[a];
            arr1.push_back(a);
        }

        while (set[b] != b)
        {
            b = set[b];
            arr2.push_back(b);
        }

        vector<int>::iterator it = arr1.begin();
        for (int i = 0, size = arr2.size(); i < size; i++)
        {
            it = find(arr1.begin(), arr1.end(), arr2[i]);
            if (it != arr1.end())
                break;
        }
        if (it != arr1.end())
            cout << *it;
        if (i != m - 1)
            cout << endl;
    }
    system("pause");
    return 0;
}