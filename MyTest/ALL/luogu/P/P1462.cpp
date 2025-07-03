#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int N = 1e4 + 3, M = 10e4 + 3;
int n, m, b, f[N], dn, eh[N], dis[N], maxf, ans = -1;

struct edge
{
	int to, val, next;
}e[M];

il void addEdge(int u, int v, int w)
{
	e[++dn].to = v;
	e[dn].val = w;
	e[dn].next = eh[u];
	eh[u] = dn;
}

struct node {
	int dis, pos;			//dis表示消耗血量，fee表示费用
	node(int x, int y) 
	{
		dis = x, pos = y;
	}
	bool operator < (const node& x) const 
	{
		return dis < x.dis;
	}
};

il int Max(int a, int b) { return a > b ? a : b; }
il int Min(int a, int b) { return a < b ? a : b; }

il void read() 
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
		maxf = Max(f[i], maxf);
	}

	for (int i = 0; i < m; i++)
	{
		rg int u, v, w; cin >> u >> v >> w;
		addEdge(u, v, w), addEdge(v, u, w);	//双向边
	}
}

il void Init()
{
	for (int i = 1; i <= n; i++)
		dis[i] = 0;
}

il bool check(int x)	//二分答案 可以抵达就返回 1 ，否则返回 0 
{
	if (f[n] > x || f[1] > x) return 0;	//f[] 有可能是 0 （优化起点检查）
	Init();
	dis[1] = b;
	priority_queue<node> q;	//优先处理距离近的点
	q.push(node(b, 1));	//传参第一个为剩余的血量，第二个为城市的编号；
	while (q.size())
	{
		rg node now = q.top();
		q.pop();
		if (now.dis<dis[now.pos]) continue;
		
		for (int i = eh[now.pos]; i; i = e[i].next)
		{
			rg int v = e[i].to, w = e[i].val;
			if (now.dis - w >= 0 && f[v] <= x)
			{
				dis[v] = Max(dis[v], now.dis - w);
				if (v == n) return 1;
				q.push(node(now.dis - w, v));
			}
		}
	}

	return 0;
}

il void solve()
{
	rg int l = Max(f[1],f[n]), r = maxf;
	while (r >= l)
	{
		rg int mid = (l + r) >> 1;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	solve();
	if (ans != -1)cout << ans << "\n";
	else cout << "AFK\n";
	return 0;
}