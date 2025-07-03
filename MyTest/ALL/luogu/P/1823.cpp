#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
#define par pair<ll,int>
const int N = 5e5 + 3;
int n;
ll ans;

il void solve()
{
	cin >> n;
	stack<par> s;
	for (int i = 1; i <= n; i++)
	{
		rg ll h; cin >> h;
		par p(h, 1);
		while (!s.empty() && s.top().first <= p.first)
		{
			ans += s.top().second;
			if (h == s.top().first) p.second += s.top().second;
			s.pop();
		}
		if (!s.empty()) ans++;
		s.push(p);
	}

}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	solve();

	cout << ans << "\n";

	return 0;
}