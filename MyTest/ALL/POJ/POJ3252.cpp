#include <iostream>
#include <queue>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ll unsigned long long
#define il inline
#define rg register
int n;
ll ans;
struct Compare {
	bool operator() (const ll& a, const ll& b) {
		return a > b;
	}
};
priority_queue<ll, vector<ll>, Compare> q;

int main()
{
	IOS_IO;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		rg int x; cin >> x;
		q.push(x);
	}

	while (q.size() > 1)
	{
		rg ll x1 = q.top(); q.pop();
		rg ll x2 = q.top(); q.pop();
		ans += x1 + x2;
		q.push(x1 + x2);
	}

	cout << ans << "\n";
	return 0;
}