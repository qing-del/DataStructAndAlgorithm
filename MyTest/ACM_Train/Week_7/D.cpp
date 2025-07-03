#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 4;
int n, m, ans;
bitset<N> used[N];
char mp[N][N];
int pi[] = { 0,0,1,-1 }, pj[] = { 1,-1,0,0 };

void dfs(int si, int sj)
{
	mp[si][sj] = '0';
	for (int k = 0; k < 4; k++)
	{
		int ii = si + pi[k], jj = sj + pj[k];
		if (ii<1 || jj<1 || ii>n || jj>m) continue;
		if (mp[ii][jj] - '0')
		{
			dfs(ii, jj);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j] - '0')
			{
				dfs(i, j);
				ans++;
			}
	cout << ans << endl;
	return 0;
}