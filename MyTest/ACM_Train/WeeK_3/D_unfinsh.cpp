#include <iostream>
#include <cstring>
using namespace std;

int n, m, a, b, s, d;
int posx[100001];
int posy[100001];

int main()
{
	while (cin >> n >> m)
	{
		if (n == m && n == 0)break;
		memset(posx, 0, sizeof(posx));
		memset(posy, 0, sizeof(posy));

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			posx[a]++;
			posy[b]++;
		}


	}
	return 0;
}