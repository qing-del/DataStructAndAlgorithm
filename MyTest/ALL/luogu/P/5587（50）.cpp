#include <bits/stdc++.h>
using namespace std;
#define il inline
#define rg register
const int N = 1e5 + 3;
stack<char> s1[N];
vector<char> s2;

il void read()
{
	rg int t = 1;
	string enter;
	while (1)
	{
		getline(cin, enter);
		if (enter == "EOF") break;
		for (int i = 0; i < enter.size(); i++)
			s1[t].push(enter[i]);
		t++;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	read(); s2.reserve(N + 10);
	rg int sum = 0;
	string re; rg int k = 1;
	while (1)
	{
		s2.clear();
		getline(cin, re);
		if (re == "EOF") break;
		for (int i = 0; i < re.size(); i++)
		{
			if (re[i] != '<')
				s2.push_back(re[i]);
			else
				if (s2.size())
					s2.pop_back();
		}

		while (s1[k].size() != s2.size())
		{
			if (s1[k].size() > s2.size())
				s1[k].pop();
			else
				s2.pop_back();
		}

		while (s1[k].size())
		{
			if (s1[k].top() == s2.at(s2.size() - 1)) sum++;
			s1[k].pop();
			s2.pop_back();
		}

		k++;
	}
	rg double T; cin >> T;
	rg double res = sum / T * 60.0;
	cout << fixed << setprecision(0) << res << "\n";
	return 0;
}