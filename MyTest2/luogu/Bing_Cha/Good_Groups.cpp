#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int x;
	cin >> x;
	vector<pair<string, string>> correct;
	for (int i = 0; i < x; i++)
	{
		pair<string, string> p1;
		cin >> p1.first >> p1.second;
		correct.push_back(p1);
	}

	int y;
	cin >> y;
	vector<pair<string, string>> error;
	for (int i = 0; i < y; i++)
	{
		pair<string, string> p1;
		cin >> p1.first >> p1.second;
		error.push_back(p1);
	}

	int g;
	cin >> g;
	map<string, int> group;
	for (int i = 0; i < g; i++)
	{
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		group.insert(pair<string, int>(s1, i));
		group.insert(pair<string, int>(s2, i));
		group.insert(pair<string, int>(s3, i));
	}

	int count = 0;
	for (auto elem : correct)
		if (group[elem.first] != group[elem.second])
			count++;

	for (auto elem : error)
		if (group[elem.first] == group[elem.second])
			count++;

    cout << count << endl;
	system("pause");
	return 0;
}