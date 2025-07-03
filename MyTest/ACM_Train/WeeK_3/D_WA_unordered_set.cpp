#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c, d;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;

        unordered_map<int, unordered_set<int>> x_map, y_map; // 用于存储按坐标分组的基地

        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            x_map[a].insert(b); // 根据 x 坐标存储
            y_map[b].insert(a); // 根据 y 坐标存储
        }

        for (int i = 0; i < m; i++)
        {
            int count = 0;
            cin >> c >> d;

            if (!c) // 轰炸垂直线 x = d
            {
                if (x_map.count(d))
                {
                    count = x_map[d].size();
                    for (int y : x_map[d]) // 删除 y 坐标
                    {
                        y_map[y].erase(d); // 从 y_map 中删除相应的 x 坐标
                    }
                    x_map.erase(d); // 删除 x_map 中的 d
                }
            }
            else // 轰炸水平线 y = d
            {
                if (y_map.count(d))
                {
                    count = y_map[d].size();
                    for (int x : y_map[d]) // 删除 x 坐标
                    {
                        x_map[x].erase(d); // 从 x_map 中删除相应的 y 坐标
                    }
                    y_map.erase(d); // 删除 y_map 中的 d
                }
            }

            cout << count << endl;
        }
        cout << endl;
    }
    return 0;
}
