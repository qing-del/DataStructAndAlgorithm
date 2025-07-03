#include <bits/stdc++.h>
using namespace std;
const int N = 24;
char mp[N][N];
bitset<N> used[N];
int H, W, si, sj, ans;
int pi[] = { 0,0,1,-1 }, pj[] = { 1,-1,0,0 };

int Max(int a, int b) { return a > b ? a : b; }

void dfs(int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		int ii = i + pi[k], jj = j + pj[k];
		if (ii<1 || jj<1 || ii>H || jj>W) continue;
		if (mp[ii][jj] == '.' && used[ii][jj] == 0)
		{
			used[ii][jj] = 1;
			ans++;
			dfs(ii, jj);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	while (cin >> W >> H)
	{
		if (W == 0 && H == 0) break;
		for (int i = 1; i < N; i++)
			used[i].reset();
		memset(mp, ' ', sizeof(mp));
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] == '@')
					si = i, sj = j;
			}

		used[si][sj] = 1;
		ans = 1;
		dfs(si, sj);
		cout << ans << endl;
	}
	return 0;
}