#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct person {
	string name;
	bool crime;
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		vector<person> arr(a);
		for (int i = 0; i < a; i++)
		{
			cin >> arr[i].name;
			arr[i].crime = false;
		}

		for (int i = 0; i < b; i++)
		{
			string input;
			cin >> input;
			for (int i = 0; i < a; i++)
			{
				if (arr[i].name == input)
				{
					arr[i].crime = true;
					break;
				}
			}
		}

		for (int i = 0; i < c; i++)
		{
			string input;
			cin >> input;
			for (int i = 0; i < a; i++)
			{
				if (arr[i].name == input)
				{
					arr[i].crime = false;
					break;
				}
			}
		}

		int count = 0;
		for (int i = 0; i < a; i++)
		{
			if (arr[i].crime)
			{
				count++;
				cout << arr[i].name << " ";
			}
		}
		if (count == 0)
			cout << "No enemy spy" << endl;
		else
			cout << endl;

	}
	
	return 0;
}