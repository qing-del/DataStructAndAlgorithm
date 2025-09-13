// 测试连接：https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71
// 二分答案 - 机器人跳跃问题
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10;
int h[N], n;

int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];

	int l = N, r = 0;
	for (int i = 0; i < n; i++)
	{
		l = Min(l, h[i]);
		r = Max(r, h[i]);
	}

	int ans = r, maxn = r;

	while (l <= r)
	{
		int mid = (l + r) >> 1;
		bool res = 1;
		int x = mid;
		for (int i = 0; i < n; i++)
		{
			x += x - h[i];
			if (x < 0)
			{
				res = 0;
				break;
			}
			else if (x >= maxn)
				break;
		}

		if (res)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}