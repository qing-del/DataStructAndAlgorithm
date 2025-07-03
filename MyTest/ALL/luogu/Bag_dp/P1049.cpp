//洛谷 P1049 链接：https://www.luogu.com.cn/problem/P1049
//属于 01背包 问题 
#include <iostream>
#include <cstring>
using namespace std;
#define ms(n,x) memset(n,x,sizeof(n))
#define il inline
#define rg register
const int V=2e4+3, N=34;
int v,n;
bool dp[V];	//表示放入的物品是否能达到这个体积 

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>v>>n;
	dp[v]=1;
	
	for(int i=0;i<n;i++)
	{
		rg int a;cin>>a;
		for(int j=0;j+a<=v;j++)
			if(dp[j+a])
				dp[j]=1;
	} 
	
	for(int i=0;i<=v;i++)
		if(dp[i])
		{
			cout<<i<<"\n";
			break;
		}
	return 0;
}