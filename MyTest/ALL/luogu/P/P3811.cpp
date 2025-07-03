#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int N = 3e6+3;
int n, p, f[N];

il void Exgcd(int a, int b, int& x, int& y)
{
	if (!b)
		x = 1, y = 0;
	else
	{
		Exgcd(b, a % b, y, x);
		y -= (int)(a / b) * x;
	}
}

il int solve(int a, int b)
{
	int x, y;
	Exgcd(a, b, x, y);
	return (x % b + b) % b;	//将逆元解限制在 (0,b]
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> p;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = (1LL * (p - p / i) * f[p % i]) % p;
	
	for (int i = 1; i <= n; i++)
		cout << f[i] << "\n";
	return 0;
}