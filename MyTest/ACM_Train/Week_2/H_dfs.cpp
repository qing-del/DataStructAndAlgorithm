#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int T;
int N, D;
int sum;

struct Node {
	vector<int> line;
	int step = 0;

	Node()
	{
		this->step = 0;
	}
}Node[MAX];

void dfs(int k)
{
	for (auto it = Node[k].line.begin(); it!=Node[k].line.end(); it++)
	{
		if (!Node[*it].step && *it)
		{
			Node[*it].step = Node[k].step + 1;
			if (Node[*it].step > D)
				sum++;

			dfs(*it);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--)
	{
		sum = 0;
		cin >> N >> D;
		for (int i = 0, len = N - 1; i < len; i++)
		{
			int a, b;
			cin >> a >> b;
			Node[a].line.push_back(b);
			Node[b].line.push_back(a);
		}

		dfs(0);

		cout << sum;
		for (int i = 0; i < N; i++)
		{
			Node[i].line.clear();
			Node[i].step = 0;
		}
	}
	return 0;
}