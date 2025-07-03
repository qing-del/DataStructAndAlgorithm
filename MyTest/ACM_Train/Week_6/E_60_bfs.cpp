#include <bits/stdc++.h>
using namespace std;
const int N = 8;
string A[N], B[N], a, b;
int step, n;
bool arrive;

void bfs()
{
	queue<string> q;
	queue<int> f;
	q.push(a);
	f.push(0);
	while (!q.empty())
	{
		string now = q.front();
		step = f.front();
		q.pop();
		f.pop();

		if (step > 10)
			break;

		if (now == b)
		{
			arrive = 1;
			break;
		}
		for (int i = 0; i < n; i++)
		{
			string temp = now;
			size_t found = temp.find(A[i], 0);
			if (found == string::npos) continue;
			temp.replace(found, A[i].size(), B[i]);
			q.push(temp);
			f.push(step + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	while (cin >> A[n] >> B[n])
	{
		n++;
		if (n >= 6) break;
	}
	if (a == b)
	{
		cout << 0 << endl;
		return 0;
	}
	else if (n == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	bfs();
		
	if (arrive)
		cout << step << endl;
	else
		cout << -1 << endl;
	return 0;
}
