#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string str; cin >> str;
	stack<char> s;
	for (int i = 0, len = str.size(); i < len; i++)
	{
		if (str[i] == '@') break;
		if (str[i] == '(')
			s.push('(');
		else if (str[i] == ')')
		{
			if (s.empty())	//如果是空的话
			{
				cout << "NO" << "\n";
				return 0;
			}
			else
				s.pop();
		}
	}
		
	if (s.empty())
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
	return 0;
}