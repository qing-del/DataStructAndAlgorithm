#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define S string

int main()
{
	int t, n, len;
	S s;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s;
		bool ok = 1;
		len = sqrt(n);
		if (pow(len, 2) != n)
		{
			cout << "No" << endl;
			continue;
		}
		for (int i = 0; i < len; i++)
			for (int j = i * len, len_a = (i + 1) * len; j < len_a; j++)
				if (i == 0 || j == i*len || j == len_a - 1 || i == len - 1)
				{
					if (s[j] != '1')
					{
						ok = 0;
						goto out;
					}
				}
				else
				{
					if (s[j] != '0')
					{
						ok = 0;
						goto out;
					}
				}
	out:
		if (ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}


	return 0;
}