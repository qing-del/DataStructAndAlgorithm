// 测试链接：https://www.luogu.com.cn/problem/P1238
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
#define pir pair<int, int>
#define mk(x,y) make_pair(x,y)
const int N = 20;
int n, m, mp[N][N], sx, sy, ex, ey, ans;
int xi[] = { 0,-1,0,1 };
int yi[] = { -1,0,1,0 };
pir path[N * N];
bool vis[N][N];

il int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
		ch = getchar();

	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void dfs(int x, int y, int i)
{
	vis[x][y] = 1;
	path[i] = mk(x, y);
	if (x == ex && y == ey)
	{
		for (int k = 1; k <= i; k++)
		{
			cout << "(" << path[k].first << "," << path[k].second << ")";
			if (k != i) cout << "->";
			else cout << endl;
		}

		ans = 1;
		vis[x][y] = 0;
		return;
	}

	for (int j = 0, nx, ny; j < 4; j++)
	{
		nx = x + xi[j], ny = y + yi[j];
		if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || !mp[nx][ny]) continue;
		dfs(nx, ny, i + 1);
	}

	vis[x][y] = 0;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mp[i][j] = read();
	sx = read(), sy = read(), ex = read(), ey = read();
	memset(vis, 0, sizeof(vis));
	dfs(sx, sy, 1);
	if (!ans) cout << "-1" << endl;
	return 0;
}