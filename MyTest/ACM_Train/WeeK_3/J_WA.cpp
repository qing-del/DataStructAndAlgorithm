#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> print;

int a, b;

bool check(const vector<bool>& bools)
{
	for (const bool& e : bools)
		if (!e) return false;
	return true;
}

bool run(vector<bool> arr, const int& s, const int& n)
{
	for (int i = 1, len = n - s; i <= len; i++)
	{
		for (int j = i - 1; j < i + s - 1; j++)
		{
			arr[print[j]-1] = true;
			b = j + 1;
		}
		if (check(arr))
		{
			a = i;
			cout << a << " " << b << endl;
			return true;
		}
		fill(arr.begin(), arr.end(), 0);
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	print.resize(n);
	vector<bool> printer(m, false);
	for (auto& elem : print)
		cin >> elem;

	for (int i = m; i < n; i++)
	{
		if (run(printer, i, n)) return 0;
	}
	return 0;
}