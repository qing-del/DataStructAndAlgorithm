// POJ 1860 Currency Exchange（货币兑换）
// 其中使用的是spfa算法 判断“正环”
//  此代码还未提交测试
// 链接：https://vjudge.net/problem/POJ-1860

#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define il inline
#define rg register
#define ll long long
#define ull unsigned ll
#define uint unsigned int
const int N = 1e2 + 3, M = 2e2 + 3;
int n, m, s, eh[N], dn, vis[N];
double dis[N], v;
bool inq[N];
struct edge {
	int to, next;
	double r, c;
}e[M];

il void addE(int u, int v, double r, double c)
{
	e[++dn].to = v;
	e[dn].r = r, e[dn].c = c;
	/*e[dn].rft = rft, e[dn].cft = cft, e[dn].rtf = rtf, e[dn].ctf = ctf;*/
	e[dn].next = eh[u];
	eh[u] = dn;				//边从 1 开始算 且 dn即为边的数量
}

il void read()
{
	IOS_IO;
	cin >> n >> m >> s >> v;
	for (int i = 0; i < m; i++)
	{
		rg int u, v;
		rg double r1, c1, r2, c2;
		cin >> u >> v >> r1 >> c1 >> r2 >> c2;
		addE(u, v, r1, c1);
		addE(v, u, r2, c2);
	}
}

//num 是拥有的货币量
il double getVal(double num, double r, double c) { return (num - c) * r; }

//是否存在“正环”
il bool spfa()
{
	queue<int> q;
	q.push(s);
	dis[s] = v;
	vis[s]++;
	inq[s] = 1;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (int i = eh[u]; i; i=e[i].next)
		{
			rg int v = e[i].to;
			rg double r = e[i].r, c = e[i].c;
			rg double res = getVal(dis[u], r, c);
			if (res > dis[v])
			{
				dis[v] = res;
				if (!inq[v])
				{
					q.push(v);
					inq[v] = 1;
					vis[v]++;
					if (vis[v] >= n) return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	IOS_IO;
	read();
	cout << (spfa() ? "YES\n" : "NO\n") ;
	return 0;
}