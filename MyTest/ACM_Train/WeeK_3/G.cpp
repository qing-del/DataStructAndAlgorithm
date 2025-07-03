#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int sum = 0;
	map<string, int> a;
	while (getline(cin,s))
	{
		if (s.empty()) break;
		a[s]++;
		sum++;
	}

	for (auto e : a)
	{
		cout << e.first << " ";
		cout << fixed << setprecision(4) << (double)((e.second / (double)sum) * 100) << endl;
	}
	return 0;
}