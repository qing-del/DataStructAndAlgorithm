#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int N = 1e6 + 3;
int high[N], val[N], n;
ll ans[N];

il ll Max(ll a, ll b)
{
	return a > b ? a : b;
}

il ll getAns()
{
	rg ll res = 0;
	for (int i = 1; i <= n; i++)
		res = Max(res, ans[i]);
	return res;
}

il void solve()
{
	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() && high[s.top()] < high[i])
		{
			ans[i] += val[s.top()];
			s.pop();
		}
		if (!s.empty()) ans[s.top()] += val[i];		//往回看
		s.push(i);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> high[i] >> val[i];
	solve();
	cout << getAns() << "\n";
	return 0;
}