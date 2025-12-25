#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10;
int n, d;
int q[N], h, t;
int qx[N], hx, tx;
struct node {
	int x, y;
};

node a[N];

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}

	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline int Abs(int a, int b) { return a > b ? a - b : b - a; }
inline int Min(int a, int b) { return a < b ? a : b; }

bool cmp(node a, node b) {
	return a.x < b.x;
}

int main()
{
	n = read(), d = read();
	for (int i = 0; i < n; i++) a[i].x = read(), a[i].y = read();
	sort(a, a + n, cmp);

	int ans = 1e6 + 10;
	for (int i = 0; i < n; i++)
	{
		while (t > h && a[q[t - 1]].y >= a[i].y)
			t--;
		q[t++] = i;

		while (tx > hx && a[qx[tx - 1]].y <= a[i].y)
			tx--;
		qx[tx++] = i;

		while (t > h && tx > hx && Abs(a[qx[hx]].y, a[q[h]].y) >= d)
		{
			ans = Min(ans, Abs(a[qx[hx]].x, a[q[h]].x));
			if (qx[hx] < q[h])
				hx++;
			else if (q[h] < qx[hx])
				h++;
			else
				h++, hx++;
		}
	}

	cout << (ans == 1e6+10 ? -1 : ans) << endl;
	return 0;
}