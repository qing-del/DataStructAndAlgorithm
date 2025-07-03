#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int Max(const int& a, const int& b)
{
	return a > b ? a : b;
}

class BigInt
{
public:
	int a[N];	//第零位没有数字
	string s;
	int size;
	BigInt(){}
	BigInt(string s)
	{
		memset(a, 0, sizeof(a));
		this->s = s;
		size = s.size();
		for (int i = size - 1; i >= 0; i--)
		{
			a[size - i] = s[i] - '0';
		}
	}

	void operator+(const BigInt& other)
	{
		int t = Max(size, other.size);
		for (int i = 1; i <= t; i++)
			a[i] += other.a[i];
		if (t > size)
			size = t;
		while (a[size + 1] != 0)
			size++;
		for(int i=1;i<=size;i++)
			if (a[i] >= 10)
			{
				a[i] -= 10;
				a[i + 1] += 1;
			}
		while (a[size + 1] != 0)
			size++;
	}

	void multiple(const BigInt& x)
	{
		for (int i = x.size; i > 0; i--)
			multiple(x.a[i], size - i);
	}

	void operator*(const BigInt& x)
	{
		for (int i = x.size; i > 0; i--)
			multiple(x.a[i], size - i);
	}

	void multiple(const int& x,int t)	//乘以整数类型
	{
		for (int i = 1; i <= size; i++)
			a[i] *= x;
		for (int i = 1; i <= size; i++)
			if (a[i] >= 10 || t > 0)
			{
 				int tmp = a[i] % 10;	//保留原来的数的个位数
				int index = i + t;
				while (a[i] >= 10 || (t > 0 && a != 0))
				{
					a[i] /= 10;			//往后取数字
					int ad = a[i] % 10;
					a[++index] += ad;
				}
				a[i] = tmp;
				size = Max(index, size);
			}
	}

	void multiple(const int& x)	//乘以整数类型
	{
		for (int i = 1; i <= size; i++)
			a[i] *= x;
		for (int i = 1; i <= size; i++)
			if (a[i] >= 10)
			{
				int tmp = a[i] % 10;	//保留原来的数的个位数
				int index = i;
				while (a[i] >= 10)
				{
					a[i] /= 10;			//往后取数字
					int ad = a[i] % 10;
					a[++index] += ad;
				}
				size = Max(index, size);
			}
	}

	void operator*(const int& x)	//乘以整数类型
	{
		for (int i = 1; i <= size; i++)
			a[i] *= x;
		for (int i = 1; i <= size; i++)
			if (a[i] >= 10)
			{
				int tmp = a[i] % 10;	//保留原来的数的个位数
				int index = i;
				while (a[i] >= 10)
				{
					a[i] /= 10;			//往后取数字
					int ad = a[i] % 10;
					a[++index] += ad;
				}
				size = Max(index, size);
			}
	}

	void Print()
	{
		for (int i = size; i > 0; i--)
			cout << a[i];
		cout << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string s1, s2; cin >> s1 >> s2;
	BigInt num1(s1); BigInt num2(s2);
	num1 * num2;
	num1.Print();
	
	return 0;
}