#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define INF 100000000 // 1e8 as an integer
const int N = 10004;

bool vis[N]; // Replace bitset with a boolean array
struct edge {
    int to, w, next;
    edge() {}
} e[N * N];

struct node {
    int id, dis;
    node() {}
    node(int _dis, int _id) {
        dis = _dis;
        id = _id;
    }
};

bool operator<(const node &a, const node &b) {
    return a.dis < b.dis; // Priority queue uses greater by default
}

int en, eh[N], n, m, T;
int p_dis[N]; // Store distances explicitly
int p_id[N];  // Store ids explicitly

inline void add_edge(int u, int v, int w) {
    en++;
    e[en].to = v;
    e[en].w = w;
    e[en].next = eh[u];
    eh[u] = en;
}

inline int Min(const int &a, const int &b) {
    return a < b ? a : b;
}

inline void Inti() {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    memset(eh, 0, sizeof(eh));
    en = 0;
    for (int i = 1; i <= n; i++) {
        p_id[i] = i;
        p_dis[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
}

inline void solve(int s) {
    priority_queue<node> q;
    p_dis[s]=INF;
    q.push(node(p_dis[s], s));
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id])
            continue;
        vis[now.id] = true;

        if (vis[n])
            return;
        for (int i = eh[now.id]; i; i = e[i].next) {
            int x = e[i].to, d = e[i].w;
            if (vis[x])
                continue;
            if (p_dis[x] < Min(p_dis[now.id], d)) {
                p_dis[x] = Min(p_dis[now.id], d);
                q.push(node(p_dis[x], x));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    int tmp=T;
    while (T--) {
        Inti();
        solve(1);
        cout << "Scenario #" << tmp - T << ":" << "\n" << p_dis[n] << "\n\n";
    }
    return 0;
}
