//洛谷 P1048 链接：https://www.luogu.com.cn/problem/P1048
//属于 01背包 模板题目 

#include <iostream>
#include <cstring>
using namespace std;
#define ms(n,x) memset(n,x,sizeof(n))
#define il inline
#define rg register
const int N=1e3+3,M=102;
int dp[N],n,t;

il int Max(int a, int b) {
	return a>b?a:b;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t>>n;
	for(int i=0;i<n;i++)
	{
		// a 为采集时间， b 为价值 
		rg int a,b; cin>>a>>b;
		for(int j=t;j>0;j--)
		{
			if(j>=a)
				dp[j]=Max(dp[j],dp[j-a]+b);
			else
				break; 
		}
	}
	
	cout<<dp[t]<<"\n";
	return 0;
}