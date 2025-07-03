//链接：https://www.luogu.com.cn/problem/P1018
//属于 高精度 + 一维dp
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
#define ms(n,x) memset(n,x,sizeof(n))
#define il inline
#define rg register
const int N = 50, K = 10;
int n, k;

il int Max(int a, int b) { return a > b ? a : b; }

struct num {
	int a[N];	//a[0] 表示有效位数
	num(string s = "") {
		ms(a, 0);
		if (s == "")
			a[0] = 1;
		else
		{
			a[0] = s.size();
			for (int i = 1; i <= s.size(); i++)
				a[i] = s[a[0] - i] - '0';
		}
	}

	num operator+(const num& x) const
	{
		num res = *this;
		res.a[0] = Max(res.a[0], x.a[0]);
		rg int carry = 0;
		for (int i = 1; i <= res.a[0]; i++)
		{
			carry = res.a[i] + x.a[i];
			res.a[i] = carry % 10;
			carry /= 10;
		}

		while (carry > 0)
			res.a[++res.a[0]] = carry % 10, carry /= 10;

		return res;
	}

	num operator*(const num& x) const
	{
		num res("");
		res.a[0] = a[0] + x.a[0];
		for (int i = 1; i <= a[0]; i++)
		{
			for (int j = 1; j <= x.a[0]; j++)
				res.a[i + j - 1] += a[i] * x.a[j];

			rg int carry = 0;
			for (int k = 1; k <= i + x.a[0] || carry > 0; k++)
			{
				carry += res.a[k];
				res.a[k] = carry % 10;
				carry /= 10;
			}
		}

		while (res.a[res.a[0]] == 0 && res.a[0] > 1)	//退除无效高位
			res.a[0]--;

		return res;
	}

	num operator*(const int& x) const
	{
		num res = *this;
		for (int i = 1; i <= a[0]; i++)
			res.a[i] *= x;

		rg int carry = 0;
		for (int i = 1; i <= a[0]; i++)
		{
			carry += res.a[i];
			res.a[i] = carry % 10;
			carry /= 10;
		}

		while (carry > 0)
			res.a[++res.a[0]] = carry % 10, carry /= 10;

		while (res.a[res.a[0]] == 0 && res.a[0] > 1)	//退除无效高位
			res.a[0]--;

		return res;
	}

	void print()
	{
		for (int i = a[0]; i > 0; i--)
			cout << a[i];
	}

	bool operator<(const num& x) const
	{
		if (a[0] != x.a[0]) return a[0] < x.a[0];
		for (int i = a[0]; i > 0; i--)
			if (a[i] != x.a[i])
				return a[i] < x.a[i];
		return 1;		//相等也为小于
	}
};

il num Max(num a, num b) { return a < b ? b : a; }

num dp[N][K], v[N][N];

//检查是否为非法状态
il bool check(int i, int j)
{
	if (i < j || i - j >= n - k) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rg string str; cin >> str;
	for (int i = 0; i < str.size(); i++)
		for (int j = 1; j <= str.size() - i; j++)
			v[i + 1][j + i] = num(str.substr(i, j));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (check(i, j)) continue;
			if (j == 1)
				dp[i][j] = num(str.substr(0, i));
			else
				for (int g = 1; g < i; g++)
					dp[i][j] = Max(dp[i][j], dp[g][j - 1] * v[g + 1][i]);
		}
	}
	num res("0");
	for (int i = 1; i < n; i++)
		res = Max(res, dp[i][k] * v[i + 1][n]);

	res.print();
	return 0;
}