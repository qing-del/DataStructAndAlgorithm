#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define S string

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, l, r;
	cin >> n;
	while (n--)
	{
		int len = 0;
		int step = 0;
		cin >> l >> r;
		for (int i = l; i <= r; i += step)
		{
			step++;
			len++;
		}
		cout << len << endl;
	}

	return 0;
}