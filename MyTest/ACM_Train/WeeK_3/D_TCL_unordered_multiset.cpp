#include <iostream>
#include <unordered_set>
using namespace std;

struct PairHash {
    template <typename T1, typename T2>
    size_t operator ()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first); 
        auto h2 = hash<T2>{}(p.second); 
        return h1 ^ h2; 
    }
};

unordered_multiset<pair<int, int>, PairHash> map;  
int n, m, x, y, c, d, num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            map.insert(make_pair(x, y));
        }

        // 处理查询
        for (int i = 0; i < m; i++) {
            num = 0;
            cin >> c >> d;
            if (map.empty()) {
                cout << "0" << endl;
            }
            else {
                if (c == 0) {
                    for (auto it = map.begin(); it != map.end();) {
                        if ((*it).first == d) {
                            num++;
                            it = map.erase(it);
                        }
                        else {
                            ++it;
                        }
                    }
                    cout << num << endl;
                }
                else {
                    for (auto it = map.begin(); it != map.end();) {
                        if ((*it).second == d) {
                            num++;
                            it = map.erase(it);
                        }
                        else {
                            ++it;
                        }
                    }
                    cout << num << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
