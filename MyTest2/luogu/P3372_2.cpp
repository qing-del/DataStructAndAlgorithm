#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
#define ll long long
#define ull unsigned long long
const int N = 1e5 + 10;
int n, m;
ll a[N];
ll t1[N], t2[N];
il int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

il ll readll()
{
	ll x = 0;
	char ch = getchar();
	while (ch < '0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

il ll lowbit(const ll& x) { return x & -x; }

void add(int l, int r, ll k)
{
	int x;
	ll sk = l * k;
	for (x = l; x <= n; x += lowbit(x))
		t1[x] += k, t2[x] += sk;
	sk = (r + 1) * k;
	for (x = r + 1; x <= n; x += lowbit(x))
		t1[x] -= k, t2[x] -= sk;
}

ll ask(int l, int r)
{
	ull res = a[r] - a[l - 1];
	ull sum1 = 0, sum2 = 0;
	int x;
	for (x = r; x; x -= lowbit(x))
		sum1 += t1[x], sum2 += t2[x];

	res += (r + 1) * sum1 - sum2;
	sum1 = 0, sum2 = 0;
	for (x = l - 1; x; x -= lowbit(x))
		sum1 += t1[x], sum2 += t2[x];

	res -= l * sum1 - sum2;
	return (ll)res;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = readll() + a[i - 1];

	int op, x, y;
	ll k;
	while (m--)
	{
		op = read();
		if (op == 1)
		{
			x = read();
			y = read();
			k = readll();
			add(x, y, k);
		}
		else
		{
			x = read();
			y = read();
			cout << ask(x, y) << endl;
		}
	}

	return 0;
}