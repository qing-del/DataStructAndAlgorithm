//测试连接：https://www.luogu.com.cn/problem/P3397
//二维差分练习题--地毯（模板题）
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1010;
int n, m;
int a[N][N];

void add(int x1, int y1, int x2, int y2)
{
	a[x1][y1]++;
	a[x2 + 1][y1]--;
	a[x1][y2 + 1]--;
	a[x2 + 1][y2 + 1]++;
}

void build()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
}

//坐标（x, y） =  （j, i）
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int x1, y1, x2, y2;
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		add(x1, y1, x2, y2);
	}

	build();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	return 0;
}