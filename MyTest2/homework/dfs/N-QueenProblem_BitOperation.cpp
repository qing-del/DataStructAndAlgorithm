// n皇后排列数（位运算优化）
// 测试链接：https://www.luogu.com.cn/problem/P1219
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
const int N = 20, ALL = 0x00001fff;
int n, ans, path[N], all;

il int lowbit(int x) { return x & -x; }

il int getLowbitPos(int x) {
	int tmp = lowbit(x);
	int l = 0, r = 32, mid;
	while (r >= l)
	{
		mid = (l + r) >> 1;
		if (tmp >> mid)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

il int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
		ch = getchar();

	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void solve(int left, int right, int cur, int i)
{
	if (i == n) {
		if (++ans > 3) return;
		for (int k = 1; k <= n; k++) cout << path[k] << " ";
		cout << endl;
		return;
	}
	int limit = left | right | cur;
	int candidate = ~limit & all;
	int choose;
	while (candidate)
	{
		choose = candidate & lowbit(candidate);
		candidate -= lowbit(candidate);
		path[i + 1] = getLowbitPos(choose);
		solve((left | choose) << 1, (right | choose) >> 1, cur | choose, i + 1);
	}
}

int main()
{
	n = read();
	for (int i = 0; i < n; i++) all |= 1 << i;
	solve(0, 0, 0, 0);
	cout << ans << endl;
	return 0;
}