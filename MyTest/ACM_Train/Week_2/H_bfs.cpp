#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, D;
		cin >> N >> D;
		vector<bool> isGo(N, false);
		vector<int> step(N , 0);

		queue<int> q;
		vector<vector<int>> rela(N);
		for (int i = 0; i < N - 1; i++) {
			int x, y;
			cin >> x >> y;
			rela[x].push_back(y);
			rela[y].push_back(x);
		}


		int pos = 0;
		q.push(0);
		while (!q.empty())
		{
			pos = q.front();
			if (step[pos] > D) break;
			q.pop();
			isGo[pos] = 1;
			int len = rela[pos].size();
			for (int i = 0; i < len; i++)
			{
				if (!isGo[rela[pos][i]])
				{
					q.push(rela[pos][i]);
					step[rela[pos][i]] = step[pos] + 1;
				}
			}
		}

		int count = 0;
		for (auto elem : isGo)
			if (!elem) count++;
		cout << count << endl;
	}
	return 0;
}