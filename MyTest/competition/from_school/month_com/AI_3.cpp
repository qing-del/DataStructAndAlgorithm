#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }

    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        UnionFind uf(100000);  // 假设最多有10^5个仙

        bool isValid = true;
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;

            if (c == 1) {
                if (uf.find(a) == uf.find(b)) {
                    continue;
                }
                uf.union_sets(a, b);
            } else if (c == 0) {
                if (uf.find(a) == uf.find(b)) {
                    isValid = false;
                }
            }
        }

        if (isValid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
