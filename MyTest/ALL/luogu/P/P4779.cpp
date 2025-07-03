#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int N = 1e5 + 3;
const int M = N << 1;
int dn, hp[N], dis[N], n, m, s;
bool used[N];	//记录是否走过
struct node {
	int dis, id;
	node(int x, int y) {
		dis = x;
		id = y;
	}
	bool operator <(const node& x) const	//反向比较记录
	{
		return x.dis < dis;
	}
};
priority_queue<node> q;
struct edge {
	int to, val, next;
}e[M];
il void addEdge(int u, int v, int w) {
	e[++dn].to = v;
	e[dn].val = w;
	e[dn].next = hp[u];
	hp[u] = dn;
}
il void Init() {
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		rg int u, v, w; cin >> u >> v >> w;
		addEdge(u, v, w);
	}
}
il void solve() {
	dis[s] = 0;
	q.push(node(0, s));
	while (q.size()) {
		node now = q.top();
		q.pop();

		if (used[now.id]) continue;	//若是已经访问过的节点 那么跳过它
		used[now.id] = 1;
		
		for (int i = hp[now.id]; i; i = e[i].next) {
			//v 是目的地 ， w 是 now -> v 的距离
			rg int v = e[i].to, w = e[i].val;
			if (now.dis + w < dis[v])
			{
				dis[v] = now.dis + w;
				q.push(node(dis[v], v));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	Init();
	solve();

	return 0;
}