#include <iostream>
using namespace std;
#define il inline
#define rg register
const int N = 2e5 + 3;
int n, k, q, lb, rb;
int a[N];

il int Min(int a, int b) { return a < b ? a : b; }
il int Max(int a, int b) { return a > b ? a : b; }

il void add(int l, int r) {
	a[l]++, a[r + 1]--;
}

il void Init() {
	for (int i = 1; i <= rb; i++)
		a[i] += a[i - 1];
}

il void process()	//进行处理
{
	for (int i = lb; i <= rb; i++)
		if (a[i] >= k)
			a[i] = 1;	//设置为合法温度
		else
			a[i] = 0;	//设置为非法温度
}

il void updata(int r)	//更新最大右边界
{
	for (int i = rb + 1; i <= r; i++)
		a[i] += a[i - 1];
	rb = r;
}

il int getSum(int l, int r) { return a[r] - a[l - 1]; }

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> q;
	lb = N;
	for (int i = 0; i < n; i++)
	{
		rg int l, r; cin >> l >> r;
		lb = Min(l, lb), rb = Max(rb, r);
		add(l, r);	//差分数组处理方式 区间修改
	}
	rb++;		//由于差分数组的性质 a[rb+1]=-1
	Init();		//还原为原数组
	process();	//处理为回答问题的数组
	Init();		//再取得前缀和


	while (q--)
	{
		rg int l, r; cin >> l >> r;
		if (r > rb) updata(r);		//大于最大右边界就更新最大右边界（更新前缀和）
		cout << getSum(l, r) << "\n";
	}
	return 0;
}