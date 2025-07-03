#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N = 1e5 + 4;
int d[N], r[N], l[N];
int n, m;

il void Init()	//初始化
{
	for (int i = 0; i <= n; i++)
	{
		l[i] = i - 1;
		r[i] = i + 1;
	}
	r[0] = 1;
	l[0] = n;
}

il void Link(int L, int R) //将 L 与 R 链接起来
{
	r[L] = R;
	l[R] = L;
}

il void insert_L(int x, int y)	//将 x 插入 y 的左侧
{
	int lx = l[x], rx = r[x], ly = l[y];
	Link(lx, rx);
	Link(ly, x);
	Link(x, y);
}

il void insert_R(int x, int y)	//将 x 插入 y 的右侧
{
	int lx = l[x], rx = r[x], ry = r[y];
	Link(lx, rx);
	Link(y, x);
	Link(x, ry);
}

il void Swap(int x, int y) //将 x 与 y 互换位置
{
	int lx = l[x], ly = l[y], rx = r[x], ry = r[y];
	Link(lx, y);
	Link(y, rx);
	Link(ly, x);
	Link(x, ry);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	while (cin >> n >> m)
	{
		Init();
		bool flag = 0;	//反转标记
		while (m--)
		{
			int a, x, y;
			cin >> a;
			if (a == 4)
				flag = !flag;
			else
			{
				if (flag)
					cin >> y >> x;
				else
					cin >> x >> y;

				if (x == y) continue;

				if (a == 1)
				{
					if (l[y] == x) continue;
					insert_L(x, y);
				}
				else if (a == 2)
				{
					if (r[y] == x) continue;
					insert_R(x, y);
				}
				else
					Swap(x, y);
			}
		}

		int pow = 0;
		ll sum = 0, ans = 0;
		for (int i = 1; i <= n; i++)
		{
			pow = r[pow];
			if (i % 2 != 0)
				sum += pow;
		}
		if (flag && n % 2 == 0)
		{
			ans = -sum;
			for (int i = 1; i <= n; i++)
				ans += i;
		}
		else
			ans = sum;

		cout << "Case " << t++ << ": " << ans << "\n";
	}
	return 0;
}