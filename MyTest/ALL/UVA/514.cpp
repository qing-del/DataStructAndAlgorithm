#include <bits/stdc++.h>
using namespace std;
#define il inline
#define rg register
const int N = 1e3 + 3;
int B[N], n;

il void Init(const int &x)
{
	B[1] = x;
	for (int i = 2; i <= n; i++)
		cin >> B[i];
}

il void solve()
{
	stack<int> s;
	rg int id = 1;	//id是B组的下标

	for (int i = 1; i <= n; i++)
	{
		if (B[id] == i)
		{
			id++;
			while (!s.empty() && B[id] == s.top())
			{
				s.pop();
				id++;
			}
		}
		else
			s.push(i);
	}

	if (id > n)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	while (cin >> n)
	{
		if (n == 0) break;
		rg int x;
		while (cin >> x)
		{
			if (x == 0)
			{
				cout << "\n";
				break;
			}
			Init(x);
			solve();
		}
	}

	return 0;
}