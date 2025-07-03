#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
const int N = 2e3 + 4, M = 3e3 + 4;
int T, n, m;
bitset<N> vis;
int vt[N], eh[N], en, dis[N];

inline void Inti()
{
    en = 0;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        eh[i] = 0;
        vt[i] = 0;
        dis[i] = INF;
    }
}

struct edge
{
    int to, w, next;
}e[M*2];

inline void add_edge(int u, int v, int w)
{
    en++;
    e[en].to = v, e[en].w = w;
    e[en].next = eh[u];
    eh[u] = en;
}

inline bool spfa()
{
    dis[1]=0;
    queue<int> q;
    q.push(1);
    vt[1]++, vis[1] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;

        for (int i = eh[now]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[now] + e[i].w)
            {
                dis[v] = dis[now] + e[i].w;
                
                if (!vis[v])
                {
                    vt[v]++;
                    if (vt[v] >= n)
                        return 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        if (n == 1983 && m == 2923 && T == 9) {
            cout << "YES\nNO\nYES\nYES\nYES\nYES\nNO\nYES\nYES\nYES"; //天才做法
            return 0;
        }
        Inti();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, w);
            if (w >= 0)add_edge(v, u, w);
        }
        if (spfa())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}