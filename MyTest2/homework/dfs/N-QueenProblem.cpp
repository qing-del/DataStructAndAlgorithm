// n皇后问题 - 这个为正常的回溯算法做法 - 排列数
// 测试链接：https://www.luogu.com.cn/problem/P1219
#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define uint unsigned int
#define il inline
#define rg register
const int N = 15;
int seq[N], n, ans, tmp[N];

il int ABS(int a, int b)
{
	if (a > b)return a - b;
	return b - a;
}

il bool check(const int& x, const int& y)
{
	for (int i = 1; i < y; i++)
		if (x == seq[i] || (ABS(x, seq[i]) == ABS(y, i)))
			return 0;
	return 1;
}

il void dfs(int x, int y)
{
	if (!check(x, y))
		return;

	seq[y] = x;

	if (y == n)
	{
		ans++;
        if(ans<=3){
            for (int i = 1; i <= n; i++)
			    cout << seq[i] << " ";
            cout<<"\n";
        }
		
		return;
	}

	for (int i = 1; i <= n; i++)
		dfs(i, y + 1);
}

int main()
{
	IOS_IO;
	cin >> n;
	for (int i = 1; i <= n; i++)
		dfs(i, 1);

	cout << ans;
	return 0;
}