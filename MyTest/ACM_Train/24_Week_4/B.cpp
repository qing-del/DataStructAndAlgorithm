#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
const int N = 15e4 + 10;
const int M = 4e4 + 10;
pair<int, int> a[N], b[M];
bitset<N> ans, t;
int n, m;

void print()
{
	for (int i = 1; i <= n; i++)
		cout << a[i].first << " ";
	cout << endl;
	for (int i = 1; i <= m; i++)
		cout << b[i].first << " ";
	cout << endl;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i].first;
		b[i].second = i;
	}
	
	sort(a+1, a + n + 1, compare);
	sort(b+1, b + m + 1, compare);

	ans.set();
	t.reset();

	for (int i = 1, j = 1; i <= m; i++)
	{
		while (j <= n && a[j].first >= b[i].first)
		{
			t.set(a[j].second);
			j++;
		}
		ans &= t >> b[i].second - 1;
	}

	cout << ans.count() << endl;

	return 0;
}