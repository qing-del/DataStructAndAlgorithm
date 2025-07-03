#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int N = 1e2 + 3;
int a[N], b[N], n, m;

il bool compare(const int& a, const int& b)
{
	return a > b;
}

il void Init()
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n, compare);	//按照优先级进行排序
}

il void solve()
{
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(i);
	rg int k = 0, w = 0, t = 0;

	while (!q.empty())
	{
		t = q.front();
		while (a[t] < b[w])
		{
			q.pop();
			q.push(t);
			t = q.front();
		}
		q.pop();
		w++, k++;
		if (t == m) break;
	}

	cout << k << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		Init();
		solve();
	}

	return 0;
}