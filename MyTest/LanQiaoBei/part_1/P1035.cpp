#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg int k; cin >> k;
	double Sn = 0;
	rg int i;
	for (i = 0; Sn <= k;)
		Sn += 1.0 / ++i;
	cout << i << "\n";
	return 0;
}