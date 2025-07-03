#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> arr;
	int max, len;
	set<int> is;
	cin >> max >> len;
	int input;
	for (int i = 0; i < len; i++)
	{
		cin >> input;
		is.insert(input);
	}
	int count = 1, mode = 1;
	char c;
	int num;
	while (cin >> c)
	{
		if (c == 'e')
		{
			cout << endl;
			arr.clear();
			is.clear();

			cin >> max >> len;
			int input;
			for (int i = 0; i < len; i++)
			{
				cin >> input;
				is.insert(input);
			}
			count = 1, mode = 1;
			continue;
		}
		if (c == 'a')
		{
			cin >> num;
			arr.insert(num);
		}
		else if (c == 'r')
		{
			if (arr.empty())
			{
				cout << "-1" << endl;
				continue;
			}
			if (mode == 1)
			{
				set<int>::iterator it = arr.begin();
				if (!is.empty() && count == *(is.begin()))
				{
					cout << *it << endl;
					is.erase(is.begin());


				}
				arr.erase(it);
				count++;

			}
			else if (mode == 2)
			{
				set<int>::iterator it = arr.end();
				it--;
				if (!is.empty() && count == *(is.begin()))
				{
					cout << *it << endl;
					is.erase(is.begin());

				}
				arr.erase(it);
				count++;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else
		{
			cin >> num;
			mode = num;
		}
	}

	return 0;
}