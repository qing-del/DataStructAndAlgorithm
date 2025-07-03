#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	while (N--)
	{
		int m;
		cin >> m;
		string s1, s2;
		int num;
		map<string, map<string, int>> a;
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2 >> num;
			a[s2][s1] += num;
		}
		
		for (const auto& elem1 : a)
		{
			cout << elem1.first << endl;
			for (const auto& elem2 : a[elem1.first])
				cout << "   |----" << elem2.first << "(" << elem2.second << ")" << endl;
		}
	}
	
	return 0;
}