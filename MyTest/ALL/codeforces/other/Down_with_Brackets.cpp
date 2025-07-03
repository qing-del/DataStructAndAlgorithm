#include <bits/stdc++.h>
using namespace std;
#define il inline

il void solve()
{
	bool fe = 0;	//第一次出现清空
	string line; cin >> line;
	stack<char> s;
	int len = line.size();
	for (int i = 0; i < len; i++)
	{
		if (line[i] == '(') s.push(line[i]);
		else if (line[i] == ')') {
			s.pop();
			if (s.empty())
			{
				if (!fe)
					fe = 1;
				else
				{
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}