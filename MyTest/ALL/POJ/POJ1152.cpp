#include <iostream>
#include <stack>
#include <cstring>
#include <sstream>
using namespace std;
#define ll long long
#define il inline
#define rg register

//Tarjan算法    找割点

//关键词：双向，目的是找割点，有多个测试数据
//割点：①非根 & 有儿子 & low[y]>=dfn[x] ②根 & 有两个儿子

const int N = 101, M = 10001;

//dfn[]是访问时间,low[]最小回溯点,t是时间,cn[]是节点孩子数量
int eh[N], n, dn, dfn[N], low[N], t, cn[N], fa[N];

//iskey[]为是否是个点，insta[]为是否在栈内
bool iskey[N];	// insta[N];
//stack<int> s;
struct edge {
	int to, next;
}e[M];

il void addEdge(int u, int v)
{
	e[++dn].to = v;
	e[dn].next = eh[u];
	eh[u] = dn;
}

il int Min(const int& a, const int& b) { return a < b ? a : b; }

il void Init()
{
	//while (s.size()) s.pop();
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	//memset(insta, 0, sizeof(insta));
	memset(eh, 0, sizeof(eh));
	memset(cn, 0, sizeof(cn));
	memset(fa, 0, sizeof(fa));
	memset(iskey, 0, sizeof(iskey));
	dn = 0, t = 0;
}

il void read()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i <= n; i++)
	{
		rg string line; getline(cin, line);
		istringstream cins(line);
		rg int x, y; cins >> x;
		if (!x) break;
		while (cins >> y)
			addEdge(x, y), addEdge(y, x);
	}
}

il void Tarjan(int u)
{
	dfn[u] = low[u] = ++t;
	for (int i = eh[u]; i; i = e[i].next)
	{
		rg int v = e[i].to;
		if (!dfn[v])
		{
			cn[u]++;
			fa[v] = u;		//记得设置父节点
			Tarjan(v);
			low[u] = Min(low[u], low[v]);	//此处用low

			if (fa[u] == 0 && cn[u] >= 2)
				iskey[u] = 1;
			if (fa[u] != 0 && low[v] >= dfn[u])
				iskey[u] = 1;
		}
		else
			low[u] = Min(low[u], dfn[v]);	//应该使用dfn来更新
	}

}

il int show()
{
	rg int ans = 0;
	for (int i = 1; i <= n; i++)
		if (iskey[i])
			ans++;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n)
	{
		if (!n) return 0;
		cin.ignore();
		Init();
		read();
		for (int i = 1; i <= n; i++)
			if (!dfn[i])
				Tarjan(i);
		cout << show() << "\n";
	}
	return 0;
}