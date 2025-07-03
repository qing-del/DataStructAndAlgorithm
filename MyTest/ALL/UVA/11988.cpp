#include <bits/stdc++.h>
using namespace std;
#define il inline

il void solve(const string& s)
{
	int len = s.size();
	list<char> con;
	list<char>::iterator it = con.begin();
	for (int i = 0; i < len; i++)
		if (s[i] == '[')
			it = con.begin();
		else if (s[i] == ']')
			it = con.end();
		else {
			it = con.insert(it, s[i]);
			it++;
		}
	
	for (it = con.begin(); it != con.end(); it++)
		cout << *it;
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string str; 
	while (cin >> str)
		solve(str);

	return 0;
}