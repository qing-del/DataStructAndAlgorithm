// 最大食物链计数
// a -> b，代表a在食物链中被b捕食
// 给定一个有向无环图，返回
// 这个图中从最初级动物到最顶级捕食者的食物链有几条
// 测试链接 : https://www.luogu.com.cn/problem/P4017
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define endl '\n'
#define ms(x, n) memset(n,x,sizeof(n))
const int P = 80112002;
const int N = 5e3 + 10;
const int M = 5e5 + 10;

struct edge {
	int to, next;
}e[M];
int n, m, cnt, h[N], deg[N], ans[N];

int q[N], f, t;

il void addEdge(int u, int v) {
	e[++cnt].to = v;
	e[cnt].next = h[u];
	h[u] = cnt;
}

int main() {
	cin >> n >> m;
	ms(0, h); ms(0, deg); ms(0, ans);
	int u, v;
	while (m--) {
		cin >> u >> v;
		addEdge(u, v);
		deg[v]++;
	}

	for (int i = 1; i < n; i++)
		if (!deg[i]) q[t++] = i, ans[i] = 1;

	int res = 0;

	while (f < t) {
		u = q[f++];
		if (!h[u]) {
			res = (res + ans[u]) % P;
			continue;
		}
		for (int i = h[u]; i; i = e[i].next)
		{
			v = e[i].to;
			if (!(--deg[v])) q[t++] = v;
			ans[v] = (ans[u] + ans[v]) % P;
		}
	}
	cout << res << endl;
	return 0;
}