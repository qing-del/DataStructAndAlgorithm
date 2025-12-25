// 测试链接 : https://www.luogu.com.cn/problem/P4779
#include <queue>
#include <cstdio>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10, M = 2e5 + 10, MAXN = (int)1e9 | 1;
int n, m, h[N], ecnt, dis[N], s;
bool vis[N];
struct edge {
	int v, w, next;
	edge(int v = 0, int w = 0, int next = 0) :
		v(v), w(w), next(next) {}
}e[M];

struct node {
	int pos, dis;
	node(int pos = 0, int dis = 0) :pos(pos), dis(dis) {}
	bool operator<(const node& x) const { return dis > x.dis; }
};
priority_queue<node> q;

int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch>'9')
		ch = getchar();

	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

void addEdge(const int& u, const int& v, const int& w)
{
	e[++ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = h[u];
	h[u] = ecnt;
}

int main()
{
	n = read(); m = read(); s = read();
	int u, v, w;
	while (m--)
	{
		u = read(); v = read(); w = read();
		addEdge(u, v, w);
	}

	for (int i = 1; i <= n; i++) dis[i] = MAXN;
	dis[s] = 0;
	q.push(node(s, 0));
	while (q.size())
	{
		u = q.top().pos; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = e[i].next)
		{
			v = e[i].v, w = e[i].w;
			if (vis[v] || dis[v] < dis[u] + w) continue;
			dis[v] = dis[u] + w;
			q.push(node(v, dis[u] + w));
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
	printf("\n");
	return 0;
}