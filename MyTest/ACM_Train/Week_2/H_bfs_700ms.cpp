#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, D;
int sum;
bool isGo[100020];
int step[100020];
vector<int> rela[100020];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		sum = 0;
		cin >> N >> D;
		memset(isGo, 0, sizeof(isGo));
		memset(step, 0, sizeof(step));
		for (int i = 0; i < N; i++)
			rela[i].clear();


		queue<int> q;
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

		for (int i = 0; i < N; i++)
			if (!isGo[i]) sum++;
		cout << sum << endl;
	}
	return 0;
}