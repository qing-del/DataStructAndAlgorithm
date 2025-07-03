#include <iostream>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

vector<int> print;
int n, m, a, b;

int main()
{
	set<int> he;
	set<int> hou;
	cin >> n >> m;
	print.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> print[i];
		he.insert(print[i]);
		if (he.size() == m)
		{
			b = i + 1;
			break;
		}
	}

	for (int i = b - 1; i >= 0; i--)
	{
		hou.insert(print[i]);
		if (hou.size() == m)
		{
			a = i + 1;
			break;
		}
	}

	cout << a << " " << b << endl;

	return 0;
}