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
        unordered_map<int, unordered_multiset<int>> x_map, y_map;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            x_map[a].insert(b);
            y_map[b].insert(a);
        }
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            cin >> c >> d;
            if (!c)
            {
                if (x_map.count(d))
                {
                    count = x_map[d].size();
                    for (int y : x_map[d])
                    {
                        y_map[y].erase(d);
                        if (y_map[y].empty()) {
                            y_map.erase(y);
                        }
                    }
                    x_map.erase(d);
                }
            }
            else
            {
                if (y_map.count(d))
                {
                    count = y_map[d].size();
                    for (int x : y_map[d])
                    {
                        x_map[x].erase(d);
                        if (x_map[x].empty()) {
                            x_map.erase(x);
                        }
                    }
                    y_map.erase(d);
                }
            }

            cout << count << endl;
        }
        cout << endl;
    }
    return 0;
}
