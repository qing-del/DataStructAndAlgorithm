//测试连接：https://www.nowcoder.com/practice/50e1a93989df42efb0b1dec386fb4ccc
//牛客的二维差分模板题
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e3 + 10;
int n, m, q;
ll a[N][N], s[N][N];

void add(int x1, int y1, int x2, int y2, int c)
{
	s[x1][y1] += c;
	s[x1][y2 + 1] -= c;
	s[x2 + 1][y1] -= c; //error-2
	s[x2 + 1][y2 + 1] += c;
}

void build()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	while (q--)
	{
		int x1, x2, y1, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		add(x1, y1, x2, y2, c);
	}

	build();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << a[i][j] + s[i][j] << ' ';
		cout << endl;
	}
	return 0;
}