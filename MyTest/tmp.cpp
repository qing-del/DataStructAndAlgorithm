#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define uint unsigned int
#define il inline
#define rg register
const int N = 1e5 + 2;;
map<int, pair<int, int>> m;
int nx[] = { 0,0,1,-1,1,1,-1,-1 }, ny[] = { 1,-1,0,0,1,-1,1,-1 };
int x0, y0, x1, y1;
bool flag;	//是否抵达

il int ABS(int a, int b)
{
	if (a > b) return a - b;
	return b - a;
}

struct node {
	int i, j, cost, step;
	node(int i = 0, int j = 0,int step=0, int cost = 0)
	{
		this->i = i;
		this->j = j;
		this->step = step;
		this->cost = step + ABS(i, x1) + ABS(j, y1);;
	}

	bool operator<(const node& x) const
	{
		return x.cost < cost;
	}
};

priority_queue<node> q;

bool check(int i, int j)
{
	auto it = m.find(i);
	if (it == m.end())
		return 0;	//不合法

	if (j >= it->second.first && j <= it->second.second)
		return 1;

	return 0;
}

int main()
{
	IOS_IO;
	cin >> x0 >> y0 >> x1 >> y1;
	rg int n; cin >> n;
	while (n--)
	{
		rg int x, l, r;
		m[x] = make_pair(l, r);
	}

	q.push(node(x0, y0, 0));


	return 0;
}