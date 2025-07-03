#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s;

bool compare_1(const pair<string, string>& a)
{
	return s == a.first;
}

bool compare_2(const pair<string, string>& a)
{
	return s == a.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	vector<pair<string, string>> a;
	while (1)
	{
		cin >> s1;
		if (s1 == "@END@") break;
		getline(cin, s2);
		if (s2[0] == ' ') s2.erase(0, 1);
		a.push_back(make_pair(s1, s2));
	}

	int time;
	cin >> time;
	getline(cin, s);
	while (time--)
	{
		getline(cin, s);
		if (s[0] == '[')
		{
			auto it = find_if(a.begin(),a.end(),compare_1);
			if (it != a.end())
				cout << it->second << endl;
			else cout << "what?" << endl;
		}
		else
		{
			auto it = find_if(a.begin(), a.end(), compare_2);
			if (it != a.end())
			{
				string output = it->first.substr(1, it->first.size() - 2);
				cout << output << endl;
			}
				
			else cout << "what?" << endl;
		}
	}
	return 0;
}