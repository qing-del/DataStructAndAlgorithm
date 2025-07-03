#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define il inline
#define rg register
const int N = 1e6 + 3;
stack<int> s;
ull a[N];
int ans;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (s.size() && a[s.top()] <= a[i])
		{
			ans ^= s.top();
			s.pop();
		}
		s.push(i);
		ans ^= i;
		cout << ans << "\n";
	}
	return 0;
}