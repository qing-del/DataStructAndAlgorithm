// 并查集模版(牛客)
// 路径压缩
// 测试链接 : https://www.nowcoder.com/practice/e7ed657974934a30b2010046536a5372
#include <iostream>
using namespace std;
#define il inline
#define endl '\n'
const int N = 1e6 + 10;
int n, m, op, s[N];

il int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

il int find(int x)
{
	return s[x] == x ? x : s[x] = find(s[x]);
}

il void merge(int a, int b)
{
	if (find(a) == find(b)) return;
	s[find(b)] = find(a);
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) s[i] = i;
	int x, y;
	while (m--)
	{
		op = read(), x = read(), y = read();
		if (op == 1)
			cout << (find(x) == find(y) ? "Yes" : "No") << endl;
		else
			merge(x, y);
	}
	return 0;
}