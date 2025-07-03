#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
const int year = 12;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg int fee; rg int me = 0, save = 0;
	for (int i = 1; i <= year; i++)
	{
		cin >> fee;
		me += 300;
		rg int hunder = (me - fee) / 100;
		if (me < fee)
		{
			cout << "-" << i << "\n";
			return 0;
		}

		if (hunder != 0)
		{
			hunder *= 100;
			me -= hunder+fee;
			save += hunder;
		}
		else
		{
			me -= fee;
		}
	}

	save *= 1.2;
	cout << save + me << "\n";
	return 0;
}