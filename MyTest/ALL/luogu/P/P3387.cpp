#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define il inline
#define rg register
const int N = 1e4 + 2, M = 1e5 + 2;
int dfn[N], low[N], f[N], n, m, scc_f[N], scc_id[N], dn, scc_dn, eh[N], scc_eh[N], t;
bool ins[N];
ll ans;

struct edge {
	int from, to, next;
	edge() {
		from = 0;
		to = 0;
		next = 0;
	}
}e[M];

struct Sedge {
	int to, next;
}scc_e[M];

il void addE(int u, int v)
{
	e[dn].from = u;
	e[dn].to = v;
	e[dn].next = eh[u];
	eh[u] = dn++;
}

il void addSE(int u, int v)
{
	scc_e[scc_dn].to = v;
	scc_e[scc_dn].next = scc_eh[u];
	scc_eh[u] = scc_dn++;
}

il int Min(int a, int b) { return a < b ? a : b; }
il int Max(ll a, ll b) { return a > b ? a : b; }

il void Init()
{
	/*t = 0;
	dn = 0;
	scc_dn = 0;*/
	ms(eh, -1);
	ms(scc_eh, -1);
	/*ms(scc_f, 0);
	ms(ins, 0);*/
}

il void read()
{
	IOS_IO;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	for (int i = 0; i < m; i++)
	{
		rg int u, v;
		cin >> u >> v;
		addE(u, v);
	}
}


stack<int> sta;
int scc_cnt;
il void Tarjan(int u)	//找出SCC分量和桥
{
	dfn[u] = low[u] = ++t;
	sta.push(u);
	ins[u] = 1;
	for (int i = eh[u]; i != -1; i = e[i].next)
	{
		rg int v = e[i].to;
		if (!dfn[v])
		{
			Tarjan(v);
			low[u] = Min(low[u], low[v]);
		}
		else
			if (ins[v])
				low[u] = Min(dfn[v], low[u]);
	}

	if (low[u] == dfn[u])
	{
		scc_cnt++;
		rg int v = -1;
		while (v != u)
		{
			v = sta.top();
			sta.pop();
			scc_id[v] = scc_cnt;
			ins[v] = 0;
			scc_f[scc_cnt] += f[v];
		}
	}
}

//int rd[N];		//SCC图入度计数
//il void Build()	//构建新的有向无环图
//{
//	for (int i = 0; i < m; i++) {
//		if (scc_id[e[i].to] != scc_id[e[i].from])
//		{
//			rg int u = scc_id[e[i].from], v = scc_id[e[i].to];
//			addSE(u, v);
//			rd[v]++;
//		}
//	}
//}

int rd[N];       // SCC图入度计数
il void Build()  // 构建新的有向无环图，并去重边
{
	set<pair<int, int>> edge_set;
	for (int i = 0; i < m; i++) {
		int u = scc_id[e[i].from];
		int v = scc_id[e[i].to];
		if (u != v && !edge_set.count({ u, v })) {
			addSE(u, v);
			edge_set.insert({ u, v });
			rd[v]++;
		}
	}
}


//il void DFS(int u, ll tmp)
//{
//	used[u] = 1;
//	scc_used[u] = 1;
//	ans = Max(tmp, ans);
//	for (int i = scc_eh[u]; i != -1; i = scc_e[i].next)
//	{
//		rg int v = scc_e[i].to;
//		if (!used[v])
//			DFS(v, tmp + scc_f[v]);
//	}
//	used[u] = 0;	//回溯（暴力求解）
//}

//struct node {
//	int id, val;
//	node(int id, int val) :id(id), val(val) {}
//};

//il void topu()
//{
//	queue<node> p;
//	for (int i = 1; i <= scc_cnt; i++)
//		if (!rd[i])
//			p.push(node(i, scc_f[i]));
//
//	while (p.size())
//	{
//		node now = p.front();
//		p.pop();
//		rg int u = now.id;
//		rg int sum = now.val;
//		ans = Max(ans, sum);
//		for (int i = scc_eh[u]; i != -1; i = scc_e[i].next)
//		{
//			rg int v = scc_e[i].to;
//			rd[v]--;
//			if (!rd[v]) p.push(node(v, sum + scc_f[v]));
//		}
//	}
//}

int dp[N]; // 存储每个SCC的最大路径和

il void topu()
{
	ms(dp, 0);
	for (int i = 1; i <= scc_cnt; ++i) {
		dp[i] = scc_f[i];
	}
	queue<int> q;
	for (int i = 1; i <= scc_cnt; ++i) {
		if (rd[i] == 0) {
			q.push(i);
		}
	}
	ans = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		ans = Max(ans, (ll)dp[u]);
		for (int i = scc_eh[u]; i != -1; i = scc_e[i].next) {
			int v = scc_e[i].to;
			if (dp[u] + scc_f[v] > dp[v]) {
				dp[v] = dp[u] + scc_f[v];
			}
			rd[v]--;
			if (rd[v] == 0) {
				q.push(v);
			}
		}
	}
}

il void solve()
{
	Init();
	read();
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			Tarjan(i);
	Build();
	topu();

	cout << ans;
}

int main()
{
	IOS_IO;
	solve();
	return 0;
}