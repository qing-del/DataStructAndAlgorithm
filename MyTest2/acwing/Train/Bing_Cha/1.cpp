#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

int find_max(const int& a, const int& b)
{
	return a > b ? a : b;
}

int find_min(const int& a, const int& b)
{
	return a > b ? b : a;
}


int find_x(int x)
{
	if (x == arr[x]) return x;
	arr[x] = find_x(arr[x]);
	return arr[x];
}

int main()
{
	int n, m;
	cin >> n >> m;
	arr.resize(n + 1);
	for (int i = 0, len = n + 1; i < len; i++)
		arr[i] = i;
	int a, b;
	char c;
	for (int i = 0; i < m; i++)
	{
		cin >> c >> a >> b;
		if (c == 'M')
		{
			if (find_x(a) == find_x(b))
				continue;
			int max = find_max(find_x(a), find_x(b));
			int min = find_min(find_x(a), find_x(b));
			arr[max] = arr[min];
		}
		else
		{
			if (find_x(a) == find_x(b))
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}