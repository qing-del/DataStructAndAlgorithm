#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N = 50 + 10;
int a[N], n;

il int add(int l, int r)
{
	if (l != r) return a[l] + a[r];
	else return a[l];
}

il int Min(int a, int b) { return a < b ? a : b; }
il int Max(int a, int b) { return a > b ? a : b; }

il void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	if ((a[1] + a[n]) % 2 == 0) {
		cout << "0\n";
		return;
	}

	int io = 60, xo = 0, id = 60, xd = 0;
	int ioi = 0, xoi = n, idi = 0, xdi = n;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % 2 == 0) {	//偶数
			if (id > a[i]) id = a[i], idi = i;
			if (xd <= a[i]) xd = a[i], xdi = i;
		}
		else {	//奇数
			if (io > a[i]) io = a[i], ioi = i;
			if (xo <= a[i]) xo = a[i], xoi = i;
		}
	}
	cout << Min(idi - 1 + n - xdi, ioi - 1 + n - xoi) << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}