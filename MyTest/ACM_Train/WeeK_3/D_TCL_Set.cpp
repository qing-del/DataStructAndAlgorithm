#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct Pos
{
	int x;
	int y;
};

class compare
{
public:
	bool operator()(const Pos& a, const Pos& b) const
	{
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		set<Pos, compare> a;
		set<Pos, compare> af;
		for (int i = 0; i < n; i++)
		{
			Pos p;
			cin >> p.x >> p.y;
			a.insert(p);
		}
		
		int style, d;
		

		for (int i = 0; i < m; i++)
		{
			int count = 0;
			cin >> style >> d;
			
			if (!style) //等于零
			{
				for (auto it = a.begin(); it != a.end();)
				{
					if ((*it).x == d)
					{
						if (af.insert(*it).second)
						{
							count++;
							it = a.erase(it);
						}
						else
						{
							it++;
						}
					}
					else
					{
						it++;
					}
				}
			}
			else
			{
				for (auto it = a.begin(); it != a.end();)
				{
					if ((*it).y == d)
					{
						if (af.insert(*it).second)
						{
							count++;
							it = a.erase(it);
						}
						else
						{
							it++;
						}
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