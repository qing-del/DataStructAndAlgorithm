#include <iostream>
using namespace std;
#include <string>
#include <bitset>
#include <vector>
const int N = 1e2 + 4;
int num[N][N];
bitset<N> boom[N] = {0};
int n, m;

void add(int y, int x)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;
			if (y + i < 0 || x + j < 0 || y + i >= n || x + j >= m) continue;
			num[y + i][x + j]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	string enter;
	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		for (int j = 0; j < m; j++)
			if (enter[j] == '*')
			{
				add(i, j);
				boom[i].set(j);
			}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (!boom[i][j])
				cout << num[i][j];
			else
				cout << '*';
		cout << endl;
	}
		
	return 0;
}