// Prim算法优化（洛谷）
// 测试链接 : https://www.luogu.com.cn/problem/P3366

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
const int N = 5e4 + 10, M = 2e5 + 10;
struct Edge {
    int v, w, next;
}e[M << 1];

struct node {
    int pos, dis;
    bool operator<(const node& x) const {
        return x.dis < dis;
    }
    node(int pos = 0, int dis = 0) : pos(pos), dis(dis) {}
};

int n, m, h[N], cnt;
bool vis[N];

il void addEdge(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = h[u];
    h[u] = cnt;
}

int main() {
    cin >> n >> m;
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int ans = 0;
    priority_queue<node> q;
    q.push(node(1, 0));
    int dis, num = 0;
    while (q.size()) {
        u = q.top().pos;
        dis = q.top().dis;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += dis;
        num++;
        if (num == n) break;
        for (int i = h[u]; i; i = e[i].next) {
            v = e[i].v, w = e[i].w;
            if (vis[v]) continue;
            q.push(node(v, w));
        }
    }
    cout << (num == n ? to_string(ans) : "orz\n") << endl;
    return 0;
}