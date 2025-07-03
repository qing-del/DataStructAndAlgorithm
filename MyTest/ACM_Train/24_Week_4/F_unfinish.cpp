#include <iostream>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
#define S string
int t;
bool canUse[100010];

class compare
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	while (cin >> n >> m)
	{
		int call = 0;
		memset(canUse, 0, sizeof(canUse));
		for (int i = 1; i <= m; i++) canUse[i] = 1;
		stack<int> s;
		set<pair<int, int>, compare> task;
		unordered_map<int, int> time;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			++time[t];
			if (time[t] == 1)
			{
				task.insert(make_pair(t, time[t]));
			}
			else
			{
				pair<set<pair<int, int>>::iterator, bool> it = task.insert(make_pair(t, time[t] - 1));
				task.erase(it.first);
				task.insert(make_pair(t, time[t]));
			}
			s.push(t);
		}
		for (int i = 0; i < n; i++)
		{
			t = s.top();
			if (canUse[t])
			{
				set<pair<int, int>>::iterator it = task.find(make_pair(t, time[t]));
				time[t]--;
				task.erase(it);
				if(time[t]!=0)
					task.insert(make_pair(t, time[t]));
				else
				{
					set<pair<int, int>>::iterator max_val = task.begin();
					while (canUse[max_val->first]&&max_val!=task.end())
						max_val++;
					if (max_val != task.end())
					{
						canUse[max_val->first] = 1;
						call++;
						canUse[t] = 0;
					}
				}
				s.pop();
			}
			else
			{
				set<pair<int, int>>::iterator min_val = --task.end();
				canUse[min_val->first] = 0;
				canUse[t] = 1;
				call++;
				set<pair<int, int>>::iterator it = task.find(make_pair(t, time[t]));
				time[t]--;
				task.erase(it);
				if (time[t] != 0)
					task.insert(make_pair(t, time[t]));
				else
				{
					set<pair<int, int>>::iterator max_val = task.begin();
					while (canUse[max_val->first] && max_val != task.end())
						max_val++;
					if (max_val != task.end())
					{
						canUse[max_val->first] = 1;
						call++;
						canUse[t] = 0;
					}
				}
				s.pop();
			}
		}
		cout << call << endl;
	}
	
	return 0;
}