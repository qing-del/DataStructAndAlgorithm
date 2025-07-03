#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int a[N];

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}