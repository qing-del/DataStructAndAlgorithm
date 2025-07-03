//错因：后面可能会出现更小的区间，并未检查到

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	vector<int> print(n);
	map<int, int> times;
	for (int i = 0; i < n; i++)
	{
		cin >> print[i];
		times[print[i]]++;
		if (times.size() == m)
		{
			b = i + 1;
			break;
		}
	}
	
	for (int i = 0, len = b; i <= len; i++)
	{
		a = i + 1;
		if (times[print[i]] >= 2)
		{
			times[print[i]]--;
		}
		else
		{
			break;
		}
	}
	
	cout << a << " "  << b << endl;

	return 0;
}