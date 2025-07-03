//洛谷 P1060 链接：https://www.luogu.com.cn/problem/P1060
//属于 01背包 问题
#include <iostream>
using namespace std;
#define il inline
#define rg register
const int N=3e4+3,M=30;
int dp[N],n,m;

il int Max(int a, int b) {
	return a>b?a:b;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		rg int v,p;
		cin>>v>>p;	// v 表示价格,  p 表示重要度 
		for(int j=n;j>=v;j--)
			dp[j]=Max(dp[j],dp[j-v]+(v*p));
	}
	
	cout<<dp[n]<<"\n";
	return 0;
} 