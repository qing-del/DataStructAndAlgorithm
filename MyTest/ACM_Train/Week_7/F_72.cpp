#include <bits/stdc++.h>
using namespace std;
const int N = 16384 + 5;
int n, m, si, sj, ei, ej;
int pi[] = { 1,-1,0,0 }, pj[] = { 0,0,1,-1 };
bool see;

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

void yingshe(vector<vector<char>>& mp)
{
	mp[ei][ej] = 'c';
	for (int i = ei + 1; i <= n; i++) //下
	{
		if (mp[i][ej] == 'X')
			break;
		mp[i][ej] = 'c';
		
	}
	for (int i = ei - 1; i > 0; i--) //上
	{
		if (mp[i][ej] == 'X')
			break;
		mp[i][ej] = 'c';
	}
	for (int j = ej + 1; j <= m; j++) //右
	{
		if (mp[ei][j] == 'X')
			break;
		mp[ei][j] = 'c';

	}
	for (int j = ej - 1; j > 0; j--) //左
	{
		if (mp[ei][j] == 'X')
			break;
		mp[ei][j] = 'c';
	}
	for (int i = ei + 1, j = ej+1; i <= n && j <= m; i++, j++)  //右下
	{
		if (mp[i][j] == 'X')
			break;
		mp[i][j] = 'c';
	}
	for (int i = ei-1, j = ej-1; i >= 1 && j >= 1; i--, j--)  //左上
	{
		if (mp[i][j] == 'X')
			break;
		mp[i][j] = 'c';
	}
	for (int i = ei-1, j = ej+1; i >= 1 && j <= m; i--, j++) //右上
	{
		if (mp[i][j] == 'X')
			break;
		mp[i][j] = 'c';
	}
	for (int i = ei+1, j = ej-1; i <= n && j >= 1; i++, j--) //左下
	{
		if (mp[i][j] == 'X')
			break;
		mp[i][j] = 'c';
	}
}

void bfs(vector<vector<char>> mp)
{
	see = 0;
	yingshe(mp);
	if (mp[si][sj] == 'c')
	{
		see = 1;
		cout << 0 << endl;
		return;
	}
	queue<Node> q;
	q.push(Node(si, sj, 0));
	mp[si][sj] = 'X';
	while (!q.empty())
	{
		Node now = q.front();
		if (mp[now.i][now.j] == 'c')
		{
			cout << now.step << endl;
			see = 1;
			break;
		}
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ii = now.i + pi[k], jj = now.j + pj[k];
			if (ii<1 || jj<1 || ii>n || jj>n || mp[ii][jj] == 'X')continue;
			q.push(Node(ii, jj, now.step + 1));
			if(mp[ii][jj]!='c') 
				mp[ii][jj] = 'X';
			else
			{
				cout << now.step+1 << endl;
				see = 1;
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<vector<char>> mp(n + 2, vector<char>(m + 2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	while (cin >> ei >> ej >> si >> sj)
	{
		if (si == 0 && sj == 0 && ei == 0 && ej == 0)
			break;
		if (si == ei && sj == ej)
		{
			cout << 0 << endl;
			continue;
		}
		bfs(mp);
		if(!see) cout << "Poor Harry" << endl;
	}

	return 0;
}