#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	pair<int, int> _11(0, 0);
	pair<int, int> _21(0, 0);
	vector<pair<int, int>> arr1;
	vector<pair<int, int>> arr2;
	string s;
	while (true)
	{
		cin >> s;
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			if (s.at(i) == 'W')
			{
				_11.first++;
				_21.first++;
			}
			else if (s.at(i) == 'L')
			{
				_11.second++;
				_21.second++;
			}
			else if (s.at(i) == 'E')
			{
				goto out;
			}
			
			if ((_11.first >= 11 || _11.second >= 11) && abs(_11.first - _11.second) > 1)
			{
				arr1.push_back(pair<int, int>(_11.first, _11.second));
				_11.first = 0;
				_11.second = 0;
			}

			if ((_21.first >= 21 || _21.second >= 21) && abs(_21.first - _21.second) > 1)
			{
				arr2.push_back(pair<int, int>(_21.first, _21.second));
				_21.first = 0;
				_21.second = 0;
			}
		}
	}

out: //退出循环
	
	for (auto elem : arr1)
		cout << elem.first << ":" << elem.second << endl;
	cout << _11.first << ":" << _11.second << endl;

	cout << endl; //换行

	for (auto elem : arr2)
		cout << elem.first << ":" << elem.second << endl;
	cout << _21.first << ":" << _21.second << endl;

	return 0;
}