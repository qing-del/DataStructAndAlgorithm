#include <iostream>
#include <string>
#include <cmath>
#define S string
using namespace std;

int n, index, len_1, len_0, mode;
bool ok = 1;
S s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int time;
	cin >> time;
	int len;
	while (time--)
	{
		cin >> n;
		index = -1;
		ok = 1;
		cin >> s;
		int result = sqrt(n) * 10;
		result = result % 10;
		if (result != 0)
		{
			cout << "No" << endl;
			continue;
		}
		len = s.size();
		for(int i =0,len_a=s.size()-1;i<len_a;i++)
			if (s[i] == '0')
			{
				mode = 1;
				index = i;
				break;
			}
		if (n != 4 && index == -1)
		{
			cout << "No" << endl;
			continue;
		}
		else if (n==4 && index==-1)
		{
			cout << "Yes" << endl;
			continue;
		}
		len_1 = index - 1;
		len_0 = len_1 - 2;
		S check, checked;
		for (int i = index, len_a = index + len_0; i < len_a; i++) check += s[i];
		for (int i = index; i < len; i += len_1)
		{
			checked = s.substr(i, len_0);
			if (check != checked && i < len - len_1)
			{
				ok = 0;
				break;
			}
			else if (i >= len - len_1)
			{
				for (char& elem : checked)
					if (elem != '1')
					{
						ok = 0;
						break;
					}
			}
		}
		if (ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
