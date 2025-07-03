#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person
{
	string num;
	int key;
};

person compare(const person& a, const person& b)
{
	if (a.num.size() == b.num.size())
	{
		int len = a.num.size();
		for (int i = 0; i < len; i++)
		{
			if (a.num.at(i) == b.num.at(i))
				continue;
			else
				return a.num.at(i) > b.num.at(i) ? a : b;
		}
	}
	else
	{
		return a.num.size() > b.num.size() ? a : b;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<person> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].num;
		arr[i].key = i + 1;
	}

	person r= arr[0];
	for (int i = 1; i < n; i++)
	{
		r = compare(r, arr[i]);
	}

	cout << r.key << endl;
	cout << r.num << endl;

}