#include <bits/stdc++.h>
using namespace std;
stack<string> back, ford;
string input, cur;

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cur = "***###acm.org/";
	while (cin >> input)
	{
		if (input == "QUIT") break;
		if (input == "VISIT")
		{
			while (!ford.empty())
				ford.pop();
			back.push(cur);
			cin >> cur;
			cout << cur << endl;
		}
		else if (input == "BACK")
		{
			if (back.empty())
			{
				cout << "Ignored" << endl;
				continue;
			}
			ford.push(cur);
			cur = back.top();
			back.pop();
			cout << cur << endl;
		}
		else
		{
			if (ford.empty())
			{
				cout << "Ignored" << endl;
				continue;
			}
			back.push(cur);
			cur = ford.top();
			ford.pop();
			cout << cur << endl;
		}
	}
	return 0;
}