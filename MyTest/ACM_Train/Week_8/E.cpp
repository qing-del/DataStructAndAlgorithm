#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 2e5 + 5;
struct edge
{
    int to, dis, next;
};
edge e[M];
int eh[N], dis[N], cnt, n, m, s;
bitset<N> vis;

struct node
{
    int dis, pos;
    node(){}
    node(int x, int y)
    {
        dis = x;
        pos = y;
    }
    bool operator <(const node& x) const
    {
        return x.dis < dis;
    }
};

priority_queue<node> q;

inline void add_edge(int u, int v, int d)
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = eh[u];
    eh[u] = cnt;
}

inline void dijkstra()
{
    dis[s] = 0;
    q.push(node(0, s));
    while (!q.empty())
    {
        node now = q.top();
        q.pop();
        if (vis[now.pos])
            continue;
        int x = now.pos, d=now.dis;
        vis[x] = 1;
        for (int i = eh[x]; i != 0; i = e[i].next)
        {
            if (dis[e[i].to] > dis[x] + e[i].dis)
            {
                dis[e[i].to] = dis[x] + e[i].dis;
                if (!vis[e[i].to])
                {
                    q.push(node(dis[e[i].to], e[i].to));
                }
            }
        }
    }
}




int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add_edge(u, v, d);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}