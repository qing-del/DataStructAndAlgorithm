#include <iostream>
using namespace std;

int x, minV, maxV;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	int temp = b;
	b = a % b;
	a = temp;
	return gcd(a, b);
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x;
		if (i == 0) minV = x;
		maxV = maxV > x ? maxV : x;
		minV = minV < x ? minV : x;
	}
	int num = gcd(maxV, minV);
	cout << minV / num << "/" << maxV / num << endl;

	return 0;
}