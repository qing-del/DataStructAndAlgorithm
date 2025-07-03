// KMP 模板提
//题目链接：https://www.luogu.com.cn/problem/P3375

#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define il inline
#define rg register
const int N = 2e6 + 2;
int pi[N], n, m;
//在 b 中找 a 的数量
il void kmp(const string& a, const string& b)
{
	ms(pi, 0);
	rg string str = a + '#' + b;
	rg int size = str.size();
	for (int i = 1; i < size; i++)
	{
		rg int len = pi[i - 1];
		while (len != 0 && str[i] != str[len])
			len = pi[len - 1];	
		if (str[i] == str[len])
			pi[i] = len + 1;
	}
}

il void printAns()
{
	for (int i = 2 * m, len = n + m; i <= len; i++)
		if (pi[i] == m)
			cout << (i - (2 * m) + 1) << "\n";
	for (int i = 0; i < m; i++)
		cout << pi[i] << " ";
	cout << "\n";
}

int main()
{
	IOS_IO;
	rg string s1, s2;
	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();
	kmp(s2, s1);
	printAns();
	return 0;
}