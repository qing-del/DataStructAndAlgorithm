#include <iostream>
using namespace std;
#include <stack>

int getmax(const int& a, const int& b)
{
	return a > b ? a : b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	stack<int> s;
	int n; cin >> n;
	int com, t;
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (com == 0)
		{
			cin >> t;
			if (s.empty())
				s.push(t);
			else
				s.push(getmax(s.top(), t));
		}
		else if (com == 1)
		{
			if (!s.empty())
				s.pop();
		}
		else
		{
			if (s.empty())
				cout << "0" << endl;
			else
				cout << s.top() << endl;
		}
	}
	return 0;
}