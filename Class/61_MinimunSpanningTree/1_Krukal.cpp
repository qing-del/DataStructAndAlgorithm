// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
const int N = 5e4 + 10, M = 2e5 + 10;
struct edge {
    int u, v, w;
    bool operator<(const edge& x) const {
        return w < x.w;
    }
}e[M];
int n, m, f[N], cnt, ans;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int a, int b, int w) {
    int fa = find(a), fb = find(b);
    if (fa != fb) 
    {
        f[fb] = fa;
        ans += w;
        ++cnt;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e + m);
    ans = 0;
    for (int i = 0; i < n; i++) f[i] = i;
    for (int i = 0; i < m; i++)
    {
        merge(e[i].u, e[i].v, e[i].w);
        if (cnt == n - 1) break;
    }
    cout << (cnt != n - 1 ? "orz" : to_string(ans)) << endl;
    return 0;
}