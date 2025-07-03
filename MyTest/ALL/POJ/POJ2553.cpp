#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
using namespace std;
#define ms(x,n) memset(x,n,sizeof(x))
#define ll long long
#define il inline
#define rg register
const int N = 5e3 + 3;
const int M = N * N;
int dfn[N], low[N], dn, t, belong[N], eh[N], sccn;
int cd[N];
int n, m;
bool insta[N];	//是否在栈内
stack<int> sta;

struct edge {
	int to, next;
}e[M];

il int Min(int a, int b) { return a < b ? a : b; }

il void Init() 
{
	ms(dfn, 0);
	ms(low, 0);
	ms(belong, 0);
	ms(eh, -1);
	ms(cd, 0);
	dn = 0, t = 0, sccn = 0;
}

il void addEdge(int u, int v)
{
	e[dn].to = v;
	e[dn].next = eh[u];
	eh[u] = dn++;
}

il void Tarjan(int u)
{
	dfn[u] = low[u] = ++t;
	insta[u] = 1;
	sta.push(u);

	for (int i = eh[u]; i != -1; i = e[i].next)
	{
		rg int v = e[i].to;
		if (!dfn[v])
		{
			Tarjan(v);

			low[u] = Min(low[u], low[v]);
		}
		else if (insta[v])
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
			belong[v] = sccn;
		}
	}
}


il void solve()
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i);

	while (sta.size())
	{
		sccn++;
		rg int v = sta.top();
		belong[v] = sccn;
		insta[v] = 0;
	}

	for(int u=1;u<=n;u++)
		for (int i = eh[u]; i != -1; i = e[i].next)
		{
			rg int v = e[i].to;
			if (belong[u] != belong[v])
				cd[belong[u]]++;
		}

}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n)
	{
		if (n == 0)
			break;
		Init();
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			rg int u, v; cin >> u >> v;
			addEdge(u, v);
		}

		solve();
		for (int i = 1; i <= n; i++)
			if (!cd[belong[i]])
				cout << i << " ";
		cout << "\n";
	}


	return 0;
}