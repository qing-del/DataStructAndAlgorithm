//洛谷 P1064 链接：https://www.luogu.com.cn/problem/P1064
//属于 多组背包 问题 
#include <iostream>
#include <cstring> 
using namespace std;
#define ms(n,x) memset(n,x,sizeof(n))
#define il inline
#define rg register
const int N = 4e4, M = 65;
int tot, dp[N], v[M], p[M], eh[M], dn, n, m;
bool vis[M];	//表示是否为配件
int cv[4], cp[4];	//用于表示 组物品 

struct edge {
	int to, next;
	edge(int to = 0, int next = 0) :
		to(to), next(next) {}
}e[M];

il void adde(int u, int v)
{
	e[++dn].to = v;
	e[dn].next = eh[u];
	eh[u] = dn;
}

il int Max(int a, int b) {
	return a > b ? a : b;
}

il void updateDp(int k)
{
	for (int i = n; i >= cp[0]; i--)
		for (int j = 0; j < k; j++)
			if (i >= cp[j])        //组内循环
				dp[i] = Max(dp[i], dp[i - cp[j]] + cv[j]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		rg int a, b, c;
		cin >> a >> b >> c;
		v[i] = a * b;		//储存的是总价值
		p[i] = a;			//储存价格 
		if (c) {
			adde(c, i);	//由主件指向附件
			vis[i] = 1;	//其为附件 
		}
	}

	for (int i = 1; i <= m; i++)
	{
		if (vis[i]) continue;	//是附件的话就跳过
		ms(cv, 0), ms(cp, 0);
		rg int cnt = 0;
		cv[cnt] = v[i], cp[cnt] = p[i];		//主件的总价值 和 主件的价格
		cnt++;
		rg int k = eh[i];
		if (k)	//拥有第一个配件 
		{
			rg int vi = e[k].to;
			cv[cnt] = cv[0] + v[vi], cp[cnt] = cp[0] + p[vi];
			k = e[k].next;
			cnt++;
		}

		if (k)	//拥有第二个配件 
		{
			rg int vi = e[k].to;
			cv[cnt] = cv[0] + v[vi], cp[cnt] = cp[0] + p[vi];
			cnt++;
			cv[cnt] = cv[1] + cv[2] - cv[0], cp[cnt] = cp[1] + cp[2] - cp[0];
			cnt++;
		}
		updateDp(cnt);
	}

	cout << dp[n] << "\n";
	return 0;
}