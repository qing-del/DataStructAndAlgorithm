#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pir pair<int, int>
#define mp(a,b) make_pair(a,b)
int n, m, a, b;

il int Min(int a, int b) { return a < b ? a : b; }

il int solve()
{
	vector<pir> all = { mp(a, m),mp(n - a + 1,m),mp(n, b),mp(n, m - b + 1) };
	int ans = n + m;
	for (pir p : all)
	{
		int res = 0;
		while (p.first > 1)
			p.first = (p.first + 1) >> 1, res++;
		while (p.second > 1)
			p.second = (p.second + 1) >> 1, res++;

		ans = Min(ans, res);
	}
	return ans + 1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m >> a >> b;
		cout << solve() << "\n";
	}
	return 0;
}