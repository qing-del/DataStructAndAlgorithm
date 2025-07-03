#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;
int a[N], n, m, ans, maxm;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + m);
	for (int i = m; i >= 1; i--)
	{
		int radio = m - i + 1;
		if (radio > n) radio = n;
		if (a[i] * radio >= maxm)
			ans = a[i], maxm = a[i] * radio;
	}
	cout << ans << " " << maxm << endl;
	return 0;
}