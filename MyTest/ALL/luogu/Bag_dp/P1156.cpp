//洛谷 P1156 链接：https://www.luogu.com.cn/record/212509826
//属于 01背包 ＋ 贪心（优先处理小时间）
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int D=130,G=105;
int dp[D];		//表示达到当前高度所剩的最大生命值 
int d,g,maxh;
struct bi{
	int t,f,h;
	bi(int t=0,int f=0,int h=0):
		t(t),f(f),h(h) {}
	bool operator<(const bi& x) const {return t<x.t;}
}a[G]; 
il int Max(int a, int b) {return a>b?a:b;}

il void solve()
{
	for(int i=1;i<=g;i++){
		rg int t=a[i].t,f=a[i].f,h=a[i].h;
		for(int j=d+maxh;j>=h;j--){
			if(dp[j-h]>=t){
				if(j>=d){
					cout<<t<<"\n";
					return;
				}
				dp[j]=Max(dp[j],dp[j-h]);
				dp[j-h]+=f;
			}	
		}
	}
	cout<<dp[0]<<"\n";
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>d>>g;
	dp[0]=10;		//初始生命值只有十 
	for(int i=1;i<=g;i++){
		cin>>a[i].t>>a[i].f>>a[i].h;
		maxh=Max(a[i].h,maxh);
	}
	sort(a+1,a+g+1);	//对时间进行排序 
	solve();
	return 0;
}