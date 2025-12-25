// 测试链接 : https://www.luogu.com.cn/problem/P2330
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 310, M = 8100;
int n, m, f[N], cnt, ans;

struct Edge {
	int u, v, w;
} e[M];


int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b, int val) {
	int fa = find(a), fb = find(b);
	if (fa != fb) 
	{
		f[fb] = fa;
		cnt++;
		ans = max(ans, val);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n; i++) f[i] = i;
	for (int i = 0; i < m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e, e + m, [](const Edge& a, const Edge& b) { return a.w < b.w; });
	ans = cnt = 0;
	for (int i = 0; i < m && cnt < n - 1; i++)
		merge(e[i].u, e[i].v, e[i].w);
	cout << cnt << " " << ans << endl;
	return 0;
}