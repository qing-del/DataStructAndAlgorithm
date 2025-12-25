// 测试链接 : https://www.luogu.com.cn/problem/U107394
// 学习 最小字典序的 拓扑排序
#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define il inline
const int N = 1e5 + 10;
int n, m, dg[N], h[N], cnt;
struct edge {
	int v, next;
}e[N];
il int Min(int a, int b) { return a < b ? a : b; }
il int Max(int a, int b) { return a > b ? a : b; }
il int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

il void addedge(int v, int u)
{
	e[++cnt].v = v;
	dg[v]++;
	e[cnt].next = h[u];
	h[u] = cnt;
}

int main()
{
	n = read(), m = read();
	while (m--) addedge(read(), read());
	priority_queue<int, vector<int>, greater<int>> q;
	int i;
	for (i = 1; i <= n; i++) if (!dg[i]) q.push(i);

	int u;
	while (q.size())
	{
		u = q.top(); q.pop();
		cout << u << ' ';
		for (i = h[u]; i; i = e[i].next) if (!--dg[e[i].v]) q.push(e[i].v);
	}
	cout << endl;
	return 0;
}