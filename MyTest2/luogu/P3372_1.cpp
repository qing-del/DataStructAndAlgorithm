#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define il inline
#define ll long long
const int N = 1e5 + 10;
int n, m;
ll a[N];
struct node {
	ll num;	// 区间和
	ll lazy;	// 懒标记
	int l, r;	// 节点代表区间
	node(ll num = 0, ll lazy = 0, int l = 0, int r = 0)
		: num(num), lazy(lazy), l(l), r(r) {}
}tree[N << 2];

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

void build(int l, int r, int pos) 
{
	tree[pos].l = l;
	tree[pos].r = r;
	if (l == r) {
		tree[pos].num = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, pos << 1);
	build(mid + 1, r, pos << 1 | 1);
	tree[pos].num = tree[pos << 1].num + tree[pos << 1 | 1].num;
}

// 下放懒标记
void pushDown(int pos)
{
	if (!tree[pos].lazy) return;
	if (tree[pos].l == tree[pos].r) 
	{
		tree[pos].lazy = 0;
		return;
	}
	
	tree[pos << 1].num += tree[pos].lazy * (tree[pos << 1].r - tree[pos << 1].l + 1);
	tree[pos << 1].lazy += tree[pos].lazy;
	

	tree[pos << 1 | 1].num += tree[pos].lazy * (tree[pos << 1 | 1].r - tree[pos << 1 | 1].l + 1);
	tree[pos << 1 | 1].lazy += tree[pos].lazy;

	tree[pos].lazy = 0;
}

void add(const int& L, const int& R, int pos, const ll& k) {
	if (L <= tree[pos].l && tree[pos].r <= R) {
		tree[pos].num += k * (tree[pos].r - tree[pos].l + 1);
		tree[pos].lazy += k;
		return;
	}

	pushDown(pos);

	int mid = (tree[pos].l + tree[pos].r) >> 1;

	if (L <= mid) 
		add(L, R, pos << 1, k);
	
	if (R > mid) 
		add(L, R, pos << 1 | 1, k);
	
	tree[pos].num = tree[pos << 1].num + tree[pos << 1 | 1].num;
}

ll ask(const int& L, const int& R, int pos) {
	if (L <= tree[pos].l && tree[pos].r <= R)
		return tree[pos].num;

	pushDown(pos);

	int mid = (tree[pos].l + tree[pos].r) >> 1;
	ll sum = 0;

	if (L <= mid) 
		sum += ask(L, R, pos << 1);
	
	if (R > mid) 
		sum += ask(L, R, pos << 1 | 1);

	return sum;
}


int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) 
        a[i] = readll();
	build(1, n, 1);

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
			add(x, y, 1, k);
		}
		else
		{
			x = read();
			y = read();
			cout << ask(x, y, 1) << endl;
		}
	}

	return 0;
}