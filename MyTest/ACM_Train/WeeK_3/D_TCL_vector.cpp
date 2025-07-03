#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;

int main()
{
	int n, m, a, b, s, d;
	while (cin >> n >> m)
	{
		if (n == m && n == 0) break;
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		
		for (int i = 0; i < m; i++)
		{
			int count = 0;
			cin >> s >> d;
			if (!s)
			{
				for (auto it = arr.begin(); it != arr.end();)
				{
					if (it->first == d)
					{
						count++;
						it = arr.erase(it);
					}
					else
					{
						it++;
					}
				}
			}
			else
			{
				for (auto it = arr.begin(); it != arr.end();)
				{
					if (it->second == d)
					{
						count++;
						it = arr.erase(it);
					}
					else
					{
						it++;
					}
				}
			}
			cout << count << endl;
		}
	}
	return 0;
}