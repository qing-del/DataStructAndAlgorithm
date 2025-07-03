#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<string, string> a; //按照名称
	unordered_map<string, string> b; //按照功能
	string s1, s2;
	while (1)
	{
		cin >> s1;
		if (s1 == "@END@") break;
		getline(cin, s2);
		if (s2[0] == ' ') s2.erase(0, 1);
		a[s1] = s2;
		b[s2] = s1;
	}

	int time;
	cin >> time;
	string s;
	getline(cin, s);
	while (time--)
	{
		getline(cin, s);
		if (s[0] == '[')
		{
			auto it = a.find(s);
			if (it != a.end())
				cout << it->second << endl;
			else cout << "what?" << endl;
		}
		else
		{
			auto it = b.find(s);
			if (it != b.end())
				cout << it->second << endl;
			else cout << "what?" << endl;
		}
	}
	return 0;
}