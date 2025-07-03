#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		bitset<16> num;
		num = n;
		string s1, s2;
		s1 = num.to_string();
		bool start = 0;
		for (char& elem : s1)
		{
			if (!start && elem - '0' == 1)
				start = 1;
			if (start)
				s2 = s2 + elem;
		}
		cout << s2 << endl;
	}
}