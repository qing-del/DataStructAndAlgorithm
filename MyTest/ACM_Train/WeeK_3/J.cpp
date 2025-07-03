#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n, m, a, b, l, r;
	cin >> n >> m;
	vector<int> print(n);
	map<int, int> times;
	bool one = true;
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
	for (int i = b; i < n; i++)
		cin >> print[i];

	for (int i = 0, len = b; i <= len; i++)
	{
		a = i + 1;
		if (times[print[i]] > 1)
		{
			times[print[i]]--;
		}
		else
		{
			break;
		}
	}
	
	l = a - 1;
	for (int i = b; i < n; i++)
	{
		r = i + 1;
		times[print[i]]++;
		while (times[print[l]] > 1)
		{
			times[print[l]]--;
			l++;
		}
		if (b - a > r - l + 1)
		{
			a = l + 1;
			b = r;
		}
	}

	cout << a << " " << b << endl;

	return 0;
}