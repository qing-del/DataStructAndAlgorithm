//题目链接：

#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define il inline
#define rg register
const int N=1e5+3;
ll a[N], dp[N];
int n, maxn;

il ll Max(ll a, ll b)
{
	return a>b?a:b;
}

int main()
{
	IOS_IO;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		rg ll x;cin>>x;
		a[x]+=x;
		maxn=Max(maxn,x);
	}
	
	dp[1]=a[1];
	for(int i=2;i<=maxn;i++)
		dp[i]=Max(dp[i-2]+a[i], dp[i-1]);       //dp 状态转移方程
		
	cout<<dp[maxn];
	return 0;
}