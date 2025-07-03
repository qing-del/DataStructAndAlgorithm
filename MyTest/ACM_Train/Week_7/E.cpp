#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
const int M = 1e5 + 3;
int n, m, si, sj, f[N][N], ans[M];
char mp[N][N];
int pi[] = { 1,-1,0,0 }, pj[] = { 0,0,1,-1 };

void dfs(int i, int j, int num)
{
	for (int k = 0; k < 4; k++)
	{
		int ii = i + pi[k], jj = j + pj[k];
		if (ii<1 || jj<1 || ii>n || jj>n || mp[ii][jj] == mp[i][j] ||f[ii][jj]) continue;
		ans[num]++;
		f[ii][jj] = num;
		dfs(ii, jj, num);
	}
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];
	int cnt = 1;
	while (m--)
	{
		cin >> si >> sj;
		if (f[si][sj] == 0)
		{
			cnt++;
			ans[cnt] = 1;
			f[si][sj] = cnt;
			dfs(si, sj, cnt);
			cout << ans[f[si][sj]] << endl;
			continue;
		}
		cout << ans[f[si][sj]] << endl;
	}
	return 0;
}