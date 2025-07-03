#include <iostream>
#include <set>
using namespace std;

class compare
{
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		return a.second > b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set<pair<int, int>, compare> arr;
	int a, b, c;
	while (1)
	{
		cin >> a;
		if (a == 0) break;
		if (a == 1)
		{
			cin >> b >> c;
			arr.insert(make_pair(b, c));
		}
		else if (a == 2)
		{
			if (arr.empty())
			{
				cout << "0" << endl;
				continue;
			}
			set<pair<int,int>>::iterator it = arr.begin();
			cout << it->first << endl;
			arr.erase(it);
		}
		else
		{
			if (arr.empty())
			{
				cout << "0" << endl;
				continue;
			}
			set<pair<int, int>>::iterator it = arr.end();
			it--;
			cout << it->first << endl;
			arr.erase(it);
		}
	}


	return 0;
}