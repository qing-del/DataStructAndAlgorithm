#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    map<int, vector<int>> map_x, map_y;
    int n, m, x, y, c, d, num;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            map_x[x].push_back(y);
            map_y[y].push_back(x);
        }

        for (int i = 0; i < m; i++)
        {
            cin >> c;
            if (c == 0)
            {
                cin >> d;
                if (!map_x[d].empty())
                {
                    num = map_x[d].size();
                    for (auto& elem : map_x[d])
                    {
                        auto& vec = map_y[elem];
                        vec.erase(remove(vec.begin(), vec.end(), d), vec.end());
                    }
                    map_x[d].clear();
                    cout << num << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
            }
            else
            {
                cin >> d;
                if (!map_y[d].empty())
                {
                    num = map_y[d].size();
                    for (auto& elem : map_y[d])
                    {
                        auto& vec = map_x[elem];
                        vec.erase(remove(vec.begin(), vec.end(), d), vec.end()); // 使用remove和erase方法
                    }
                    map_y[d].clear();
                    cout << num << endl; // 添加换行
                }
                else
                {
                    cout << "0" << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
