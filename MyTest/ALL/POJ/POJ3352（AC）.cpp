#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define ms(x,n) memset(x,n,sizeof(x))
#define ll long long
#define il inline
#define rg register
const int N = 1e3 + 3;
const int M = N << 1;
int dfn[N], low[N], dn, t, scc_id[N], eh[N], scc[N], sccn;
int n, m;
bool insta[N];	//是否在栈内
stack<int> sta;

struct edge {
	int to, next;
	bool isbridge;  // 移除了初始化

	// 添加构造函数来初始化 isbridge
	edge() : to(0), next(-1), isbridge(false) {}
	edge(int t, int n, bool b = false) : to(t), next(n), isbridge(b) {}
}e[M];

il int Min(int a, int b) { return a < b ? a : b; }

il void Init() 
{
	ms(eh, -1);
}

il void addEdge(int u, int v)
{
	e[dn] = edge(v, eh[u]);  // 使用构造函数初始化
	eh[u] = dn++;
}

il void Tarjan(int u, int fa)
{
	dfn[u] = low[u] = ++t;
	insta[u] = 1;
	sta.push(u);

	for (int i = eh[u]; i != -1; i = e[i].next)
	{
		rg int v = e[i].to;
		if (!dfn[v])
		{
			Tarjan(v, u);

			if (low[v] > dfn[u])
				e[i].isbridge = e[i ^ 1].isbridge = 1;

			low[u] = Min(low[u], low[v]);
		}
		else if (fa != v)
			low[u] = Min(low[u], dfn[v]);
	}

	if (low[u] == dfn[u])
	{
		sccn++;
		rg int v = -1;
		while (v != u)
		{
			v = sta.top();
			sta.pop();
			insta[v] = 0;
			scc_id[v] = sccn;
		}
	}
}

int rd[N];	//计算度
il int solve()
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i, -1);

	while (sta.size())
	{
		sccn++;
		rg int v = sta.top();
		insta[v] = 0;
		sta.pop();
		scc_id[v] = sccn;
	}

	rg int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = eh[i]; j != -1; j = e[j].next)
		{
			if (e[j].isbridge)
			{
				rg int v = e[j].to;
				rd[scc_id[v]]++;
			}
		}
	
	for (int i = 1; i <= sccn; i++)
		if (rd[i] == 1)
			ans++;

	return (ans + 1) / 2;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Init();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		rg int u, v; cin >> u >> v;
		addEdge(u, v), addEdge(v, u);
	}
	cout << solve() << "\n";
	return 0;
}