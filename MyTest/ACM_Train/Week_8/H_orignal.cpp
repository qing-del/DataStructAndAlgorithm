#include <bits/stdc++.h>
using namespace std;
#define INF 1e8
const int N = 1e4 + 4;
bitset<N> vis;
struct edge
{
	int to, w, next;
	edge() {}
}e[N * N];
struct node
{
	int id, dis;
	node() {}
	node(int dis, int id)
	{
		this->dis = dis;
		this->id = id;
	}
	bool operator <(const node& x) const	//优先队列承重大顶堆
	{
		return x.dis < dis;
	}
}p[N];
int en, eh[N], n, m, T;
inline void add_edge(int u, int v, int w)
{
	en++;
	e[en].to = v;
	e[en].w = w;
	e[en].next = eh[u];
	eh[u] = en;
}

inline int Min(const int& a, const int& b)
{
	return a < b ? a : b;
}

inline void Inti()
{
	cin >> n >> m;
	vis.reset();
	for (int i = 1; i <= m; i++)
	{
		p[i].id = i, p[i].dis = 0;
		int u, v, w; cin >> u >> v >> w;
		add_edge(u, v, w); add_edge(v, u, w);
	}
}

inline void solve(int s)
{
	priority_queue<node> q;
	p[s].dis = INF;
	q.push(node(p[s].dis, s));
	while (!q.empty())			//利用bfs
	{
		node now = q.top();
		q.pop();
		if (vis[now.id])		//在此点“观察”过就下一轮
			continue;
		vis[now.id] = 1;		//标记这个点站过

		if (vis[n])
			return;
		for (int i = eh[now.id]; i; i = e[i].next)	//站在这个点上“观察”
		{
			int x = e[i].to, d = e[i].w;
			if (vis[x]) continue;
			if (p[x].dis < Min(p[now.id].dis, d))	//放行条件就是能够使该点的承重更新（更大方向）
			{
				p[x].dis = Min(p[now.id].dis, d);
				q.push(node(p[x].dis, x));
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> T;
	int tmp = T;
	while (T--)
	{
		Inti();	//初始化
		solve(1);
		cout << "Scenario #" << tmp - T << ":" << "\n" << p[n].dis << "\n\n";

	}

	return 0;
}