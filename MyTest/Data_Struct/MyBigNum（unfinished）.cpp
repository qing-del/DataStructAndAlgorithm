#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define uint unsigned int
#define il inline
#define rg register

class BigNum {			//一般在数组第零位存储有效位的位数
	const static int N = 1e6+3;	//表示位数
public:
	vector<int> num;
	//vector<int> frac;	//小数部分
	//bool nagetive;	//是否为负数
	BigNum(string s="") {
		num.reserve(N);
		int size = s.size();
		num.resize(size + 1);
		for (int i = 1; i <= size; i++)
			num[i] = s[size - i] - '0';	//逆序储存

		num[0] = num.size() - 1;
	}

	int cmp(const vector<int>& a, const vector<int>& b)
	{
		if (a[0] != b[0]) 
			return (a[0] > b[0] ? 1 : -1);
		for (int i = a[0]; i > 0; i--)
			if (a[i] != b[i])
				return (a[i] > b[i] ? 1 : -1);
		return 0;
	}

	void shiftLeft(vector<int> &x, int offset)	//向左偏移 offset 位
	{
		for (int i = 1; i <= x[0] - offset; i++)
			x[i] = x[i + offset];
		x[0] -= offset;
		x.resize(x[0]+1);
	}

	void shiftRight(vector<int>& x, int offset) //向右偏移 offset 位
	{
		int tmp = x[0];
		x[0] += offset;
		x.resize(x[0] + 1);
		for (int i = tmp; i > 0; i--)
			x[i + offset] = x[i];
		for (int i = 1; i <= offset; i++)
			x[i] = 0;
	}

	void div_sub(vector<int>& a, vector<int>& b)	//除法专用减法（a - b）
	{
		for (int i = 1; i <= b[0]; i++)
		{
			a[i] -= b[i];
			if (a[i] < 0)
				a[i + 1]--, a[i] += 10;
		}

		while (a[a[0]] == 0)
			a.pop_back(), a[0]--;
	}

	void add(const BigNum& x)	//高精度加法
	{

	}

	int BigNumCmp(const BigNum& a, const BigNum& b)		//高精度比较 a 与 b 的关系
	{

	}

	void subtract(const BigNum& x)	//高精度减法
	{

	}

	void multiply(const int& x)		//高精度乘法（高×单）
	{
		if (x == 0 || (num[0]==1 && num[1]==0))		//乘以 0 
		{
			num.resize(2, 0);
			num[0] = 1;
			return;
		}

		for (int i = 1; i < num.size(); i++)
			num[i] = num[i] * x;

		int carry = 0;
		for (int i = 1; i < num.size(); i++)
		{
			carry += num[i];
			num[i] = carry % 10;
			carry /= 10;
		}

		while (carry > 0)
		{
			int tmp = carry % 10;
			num.push_back(tmp);
			carry /= 10;
		}

		num[0] = num.size() - 1;
	}

	void multiply(const BigNum& x)	//高精度乘法（高×高）
	{
		if ((x.num[0] == 1 && x.num[1] == 0) && (num[0] == 1 && num[1] == 0))		//乘以0
		{
			num.resize(2, 0);
			num[0] = 1;
			return;
		}

		vector<int> res(num[0] + x.num[0] + 1, 0);
		res[0] = res.size() - 1;
		for (int i = 1; i <= num[0]; i++)
		{
			for (int j = 1; j <= x.num[0]; j++)
				res[i + j - 1] += num[i] * x.num[j];

			int carry = 0, k = 1;					//辅助变量
			while (carry > 0 || k <= i + x.num[0])	//进位处理
			{
				carry += res[k];
				res[k] = carry % 10;
				carry /= 10;
				k++;
			}
		}
		while (!res[res[0]] && res[0] > 1)
		{
			res.pop_back();
			res[0]--;
		}
		num = res;
	}

	void divide(const int& x)	//高 / 单 （向下取整）
	{
		if (x == 0 || (num[0]==1 && num[1]==0))
			return;
		ll carry = 0;
		vector<int> res(num[0] + 1, 0);
		res[0] = num[0];
		for (int i = num[0]; i > 0; i--)
		{
			carry *= 10;
			carry += num[i];
			if (carry >= x)
			{
				res[i] = carry / x;
				carry %= x;
			}
		}

		//cout << carry;	//carry是余数
		while (res[res[0]] == 0 && res[0] > 0)
			res.pop_back(), res[0]--;

		num = res;
	}

	void divide(const int& x, const int& n)	//高 / 单 （保留 n 位小数）
	{
		int carry = 0;

	}

	void divide(BigNum x)	//高 / 高 （得到高精度商）（无小数部分）
	{
		int isrun = cmp(this->num, x.num);
		if (isrun < 0)
		{
			num.resize(2, 0);
			num[0] = 1;
		}
		else if (isrun == 0)
			num.resize(2, 1);
			

		BigNum res;
		int size = this->num[0] - x.num[0] + 1;
		res.num.resize(size + 1, 0);
		res.num[0] = size;

		int offset = this->num[0] - x.num[0];
		shiftRight(x.num, offset);
		
		for (int i = res.num[0]; i > 0; i--)
		{
			isrun = cmp(this->num, x.num);
			while (isrun > 0)
			{
				div_sub(this->num, x.num);
				res.num[i]++;
				isrun = cmp(this->num, x.num);
			}
			if (isrun == 0)
			{
				res.num[i]++;
				break;
			}
			shiftLeft(x.num, 1);
		}
		*this = res;
		while (num[num[0]] == 0 && num[0] > 0)
			num.pop_back(), num[0]--;
	}

	void mod(const BigNum& x)	//高 / 高（得到高精度余数）
	{

	}

	void print()
	{
		for (int i = num[0]; i > 0; i--)	//逆序输出
			cout << num[i];
	}

	void println()
	{
		for (int i = num[0]; i > 0; i--)	//逆序输出
			cout << num[i];
		cout << "\n";
	}
};

void Ts_mul_1()
{
	IOS_IO;
	rg string s;
	rg int x;
	cin >> s >> x;
	BigNum a(s);
	a.multiply(x);
	a.println();
}

void Ts_mul_2()
{
	IOS_IO;
	rg string a, b;
	cin >> a >> b;
	BigNum x(a);
	x.multiply(BigNum(b));
	x.println();
}

void Ts_div_1()
{
	rg string s;
	rg int x;
	cin >> s >> x;
	BigNum a(s);
	a.divide(x);
	a.println();
}

void Ts_div_2()
{
	rg string a, b;
	cin >> a >> b;
	BigNum x(a);
	x.divide(BigNum(b));
	x.println();
}

int main()
{
	IOS_IO;
	//Ts_mul_1();
	//Ts_mul_2();
	//Ts_div_1();
	Ts_div_2();
	return 0;
}