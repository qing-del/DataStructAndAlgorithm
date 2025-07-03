#include <bits/stdc++.h>
using namespace std;
int pi[] = { 1,-1,2,2,-2,-2,1,-1,2,2,-2,-2 }, pj[] = { 2,2,1,-1,1,-1,-2,-2,2,-2,2,-2 };
bool used[21][21];
int si, sj;

struct Node
{
	int i, j, step;
	Node() {}
	Node(int i, int j, int step)
	{
		this->i = i;
		this->j = j;
		this->step = step;
	}
};

void bfs()
{
	queue<Node> q;
	q.push(Node(si, sj, 0));
	used[si][sj] = 1;
	while (!q.empty())
	{
		Node p = q.front();
		if (p.i == 1 && p.j == 1)
		{
			cout << p.step << endl;
			return;
		}
		q.pop();
		for (int k = 0; k < 12; k++)
		{
			int ii = p.i + pi[k], jj = p.j + pj[k];
			if (ii < 1 || jj < 1 || ii>20 || jj>20) continue;
			if (used[ii][jj]) continue;
			q.push(Node(ii, jj, p.step + 1));
			used[ii][jj] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> si >> sj)
	{
		memset(used, 0, sizeof(used));
		bfs();
	}
	return 0;
}