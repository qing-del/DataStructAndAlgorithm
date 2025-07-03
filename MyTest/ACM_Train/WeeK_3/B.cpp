#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	
	while (cin >> N)
	{
		if (N == 0) break;
		string s;
		map<string, int> a;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			a[s]++;
		}

		pair<string, int> max = *(a.begin());
		for (auto elem : a)
		{
			if (max.second < elem.second)
				max = elem;
		}
		
		cout << max.first << endl;
	}
	
	return 0;
}