#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
int si, sj, ei, ej, n, ans;
bitset<N> used[N];
char mp[N][N];
int pi[] = { 0,0,1,-1 }, pj[] = { 1,-1,0,0 };

struct Node
{
	int i, j, step;
	Node(){}
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
		Node now = q.front();
		if (now.i == ei && now.j == ej)
		{
			ans = now.step;
			break;
		}
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ii = now.i + pi[k], jj = now.j + pj[k];
			if (ii<1||jj<1||ii>n||jj>n||mp[ii][jj] == '1'||used[ii][jj]) continue;
			used[ii][jj] = 1;
			q.push(Node(ii, jj, now.step + 1));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mp[i][j];
	cin >> si >> sj >> ei >> ej;
	bfs();
	cout << ans << endl;
	return 0;
}