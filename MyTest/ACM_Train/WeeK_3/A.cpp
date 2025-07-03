#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	int p;
	while (cin >> n >> m)
	{
		set<int> a;
		set<int> b;

		for (int i = 0, len = n; i < len;)
		{
			cin >> p;
			if (a.insert(p).second)
			{
				i++;
			}
		}

		for (int i = 0, len = m; i < len;)
		{
			cin >> p;
			if (b.insert(p).second)
			{
				i++;
			}
		}

		for (auto elem : b)
			a.insert(elem);

		for (auto elem : a)
			cout << elem << " ";
		cout << endl;

	}
	return 0;
}