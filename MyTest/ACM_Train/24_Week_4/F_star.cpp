#include <iostream>
#include <bitset>
#include <set>
#include <map>
using namespace std;
const int N = 1e5 + 1;
const int MV = 1e9 + 1;
int a[N], b[N], pos;
map<int, int> T_n;
bitset<N> canUse;
set<pair<int, int>> xu;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		canUse.reset();
		T_n.clear();
		xu.clear();
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		for (int i = n; i >= 1; i--)
		{
			if (T_n[a[i]]) pos = T_n[a[i]];
			else pos = n + 2;  //如果没有这个值说明后面没有出现要用这个模板的位置，直接记为 n+2
			T_n[a[i]] = i;
			b[i] = pos;
		}

		for (int i = 1; i <= m; i++)
		{
			canUse.set(i);
			if (!T_n[i]) T_n[i] = N + 1; //记为题目中用不上的模板

			xu.insert(make_pair(T_n[i], i));
			//会自动排序在（后面用不上的模板的前面） 第二个值即为模板号
		}
		b[n] = n + 1; //标记最后一个任务的最后一个为空
		int call = 0;
		for (int i = 1; i <= n; i++)
		{
			T_n[a[i]] = b[i];
			xu.insert(make_pair(b[i], a[i]));
			if (!canUse[a[i]])
			{
				call++;
				if (b[i] != n + 2)
				{
					canUse.set(a[i]);
					canUse.reset((--xu.end())->second);
				}
				xu.erase(--xu.end());	//去除掉 xu 中储存的这个模板
			}
			else
			{
				xu.erase(xu.begin());	//去除掉下一个要开始的的任务
			}
		}
		cout << call << endl;

	}

	return 0;
}