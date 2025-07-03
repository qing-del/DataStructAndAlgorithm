#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int c, u, w, v, val;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, q;
	while (cin >> N >> q)
	{
		vector<deque<int>> d(N + 1);
		while (q--)
		{
			cin >> c;
			if (c == 1)
			{
				cin >> u >> w >> val;
				if (!w)
				{
					d[u].push_front(val);
				}
				else
				{
					d[u].push_back(val);
				}
			}
			else if (c == 2)
			{
				cin >> u >> w;
				if (!d[u].empty())
				{
					if (!w)
					{
						cout << d[u].front() << endl;
						d[u].pop_front();
					}
					else
					{
						cout << d[u].back() << endl;
						d[u].pop_back();
					}
				}
				else
				{
					cout << "-1" << endl;
				}
			}
			else
			{
				cin >> u >> v >> w;
				if (d[v].empty()) continue;
				if (!w)
					d[u].insert(d[u].end(), d[v].begin(), d[v].end());
				else
					d[u].insert(d[u].end(), d[v].rbegin(), d[v].rend());	
				d[v].clear();
			}
		}
	}

	return 0;
}
