// 这是平替的题目
// 测试链接 : https://www.luogu.com.cn/problem/P1194
#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define il inline
const int N = 510;
int n, b, g[N][N], cnt;
bool vis[N];

struct node {
	int pos, dis;
	node(int pos = 0, int dis = 0) : pos(pos), dis(dis) {}
	bool operator < (const node& x) const {
		return dis > x.dis;
	}
};

int main()
{
	cin >> b >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	int ans = 0, u, v, dis;
	priority_queue<node> q;
	q.push(node(1, b));
	while (q.size())
	{
		u = q.top().pos;
		dis = q.top().dis;
		q.pop();

		if (vis[u]) continue;
		vis[u] = 1;
		ans += dis;
		cnt++;
		if (cnt == n) break;
		for (v = 1; v <= n; v++)
			if (v != u && !vis[v])
				q.push(node(v, g[u][v] == 0 || g[u][v] > b ? b : g[u][v]));
	}
	cout << ans << endl;
	return 0;
}