#include <iostream>
#include <unordered_set>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c, d;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        unordered_set<pair<int, int>, pair_hash> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr.insert(make_pair(a, b));
        }

        for (int i = 0; i < m; i++)
        {
            int count = 0;
            cin >> c >> d;
            if (!c)
            {
                for (auto it = arr.begin(); it != arr.end();)
                {
                    if (it->first == d)
                    {
                        it = arr.erase(it);
                        count++;
                    }
                    else
                    {
                        it++;
                    }
                }
            }
            else
            {
                for (auto it = arr.begin(); it != arr.end();)
                {
                    if (it->second == d)
                    {
                        it = arr.erase(it);
                        count++;
                    }
                    else
                    {
                        it++;
                    }
                }
            }
            cout << count << endl;
        }
        cout << endl;
       
    }
    return 0;
}
