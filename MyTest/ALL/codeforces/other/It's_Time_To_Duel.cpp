#include <bits/stdc++.h>
using namespace std;
#define il inline
int n;
string line;

il bool solve()
{
	cin >> n; cin.ignore();
	getline(cin, line);
	if (line.find("0")!=string::npos && line.find("0 0")==string::npos)
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--)
		cout << (!solve() ? "Yes\n" : "No\n");
	return 0;
}