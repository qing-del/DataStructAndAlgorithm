#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c + b > 140 && b * 7 + c * 3 >= 800)
		{
			cout << "Excellent" << endl;
		}
		else
		{
			cout << "Not excellent" << endl;
		}
	}
}