#include <iostream>
#include <stack>
#define ll long long
using namespace std;
const int N = 8e4 + 5;
int a;
stack<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		while (!s.empty() && a >= s.top())
			s.pop();
		ans += s.size();
		s.push(a);
	}
	cout << ans;
	return 0;
}
