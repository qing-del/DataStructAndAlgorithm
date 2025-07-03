#include <bits/stdc++.h>
using namespace std;
int pi[] = { 1,-1,0,0 }, pj[] = { 0,0,1,-1 };
const int N = 2e3 + 4;
char mp[N][N];
int n, m, si, sj;
bool yes;

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
	mp[si][sj] = '#';
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ii = now.i + pi[k], jj = now.j + pj[k];
			if (ii<1 || jj<1 || ii>n || jj>m) continue;
			if (mp[ii][jj] == '#') continue;
			if (mp[ii][jj] == 'd')
			{
				yes = 1;
				cout << now.step + 1 << endl;
				return;
			}
			q.push(Node(ii, jj, now.step + 1));
			mp[ii][jj] = '#';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == 'm')
				si = i, sj = j;
		}
	bfs();
	if (!yes) cout << "No Way!" << endl;
	return 0;
}