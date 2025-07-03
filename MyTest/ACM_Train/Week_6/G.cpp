#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 2;
int mp[M][M], m, n, a, b, c, pay, coin[M][M];
int x[] = { 0,0,1,-1 }, y[] = { 1,-1,0,0 };
bitset<M> bit[M];
bool arrive;

int Min(int a, int b) { return a > b ? b : a; }

void dfs(int i, int j, int cost, int color, bool mofa)
{
	if (i <= 0 || j <= 0 || i > m || j > m)
		return;

	if (coin[i][j] == 0)
	{
		coin[i][j] = cost;
	}
	else
	{
		if (coin[i][j] <= cost)
			return;
		else
			coin[i][j] = cost;
	}

	if (i == m && j == m)
	{
		arrive = 1;
		if (pay == 0) pay = cost;
		else pay = Min(pay, cost);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int ii = i + x[k], jj = j + y[k];
		if (!bit[ii][jj])
		{
			if (mofa)
			{
				if (mp[ii][jj] == -1)
					continue;
				else if (mp[ii][jj] == color)
				{
					bit[ii].set(jj);
					dfs(ii, jj, cost, color, 0);
					bit[ii].reset(jj);
				}
				else
				{
					bit[ii].set(jj);
					dfs(ii, jj, cost + 1, mp[ii][jj], 0);
					bit[ii].reset(jj);
				}
			}
			else
			{
				if (mp[ii][jj] == color)
				{
					bit[ii].set(jj);
					dfs(ii, jj, cost, color, 0);
					bit[ii].reset(jj);
				}
				else if (mp[ii][jj] != -1)
				{
					bit[ii].set(jj);
					dfs(ii, jj, cost + 1, mp[ii][jj], 0);
					bit[ii].reset(jj);
				}
				else
				{
					bit[ii].set(jj);
					dfs(ii, jj, cost + 2, color, 1);
					bit[ii].reset(jj);
				}

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	memset(mp, -1, sizeof(mp));
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		mp[a][b] = c;
	}

	bit[1].set(1);
	dfs(1, 1, mp[1][1], 0, 0);

	if (arrive)
		cout << pay << endl;
	else
		cout << -1 << endl;
	return 0;
}