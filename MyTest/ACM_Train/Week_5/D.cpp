#include <iostream>
using namespace std;
#include <string>
#include <cstring>
const int N = 5e1 + 5;
string a[N];
char key[33];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(key, '*', sizeof(key));
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string enter;
	cin >> enter;
	int size = enter.size();
	for (int i = 0; i < n; i++)
	{
		bool pass = 1;
		for (int j = 0; j < size; j++)
			if (a[i][j] != enter[j])
			{
				pass = 0;
				break;
			}
		
		if (pass)
		{
			key[a[i][size] - 'A' + 3] = a[i][size];
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = i * 8; j < 8 * (i+1); j++)
		{
			cout << key[j];
		}
		cout << endl;
	}
	return 0;
}