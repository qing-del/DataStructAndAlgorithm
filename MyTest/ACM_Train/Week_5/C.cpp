#include <iostream>
using namespace std;
#include <queue>
#include <bitset>
queue<int> q;
const int N = 1e4 + 5;
bitset<N> bit;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bit.reset();
	int m, n; cin >> m >> n;
	int pre, x;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (!bit[x])
		{
			if (q.size() != m)
			{
				q.push(x);
				bit.set(x);
				count++;
			}
			else
			{
				pre = q.front();
				q.pop();
				bit.reset(pre);
				q.push(x);
				bit.set(x);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}