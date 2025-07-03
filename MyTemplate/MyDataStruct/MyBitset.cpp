#include <iostream>
#include <random>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;

class Bitset {
	int size;
	int* bit;
public:
	Bitset(int n = 31) {
		size = (n + 31) / 32;
		bit = new int[size];
		for (int i = 0; i < size; i++)
			bit[i] = 0;
	}

	~Bitset() {
		delete[] bit;
	}
private:
	//inline int count()
//{
//	int t = 5;
//	bitset<N> ans = bit;
//	bitset<N> tmp = 0;
//	bitset<N> step = 1;
//	for (int i = 1; i <= 5; i++)
//	{
//		tmp = step;
//		for (int j = i; j < t; j++)
//			tmp |= tmp << (1 << j);
//		
//		step = step | (step << (1 << (i - 1)));
//	}
//
//	return (int)ans.to_ulong();
//}

	inline int count(int x) {
		int step = 1;
		for (int i = 1; i <= 5; i++)
		{
			int tmp = step;
			for (int j = i; j < 5; j++)
				tmp |= tmp << (1 << j);

			x = (x & tmp) + ((x >> (1 << (i - 1))) & tmp);
			step = step | (step << (1 << (i - 1)));
		}
		return x;
	}


public:
	inline void set() {
		for (int i = 0; i < size; i++)
			bit[i] = ~0;
	}

	inline void reset() {
		for (int i = 0; i < size; i++)
			bit[i] = 0;
	}

	inline int offset(const int& x) {
		return x % 32;
	}

	inline void set(int x) {
		bit[x / 32] |= (1 << (offset(x)));
	}

	inline void reset(int x) {
		bit[x / 32] &= ~(1 << (offset(x)));
	}

	inline int count() {
		int res = 0;
		for (int i = 0; i < size; i++)
			res += count(bit[i]);
		return res;
	}

	inline bool operator[](int x) {
		return (bit[x / 32] >> offset(x)) & 1;
	}
};

inline int rdi(int l, int r)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> distrib(l, r);
	return distrib(gen);
}

bool a[N];int c[N];

//测试增加
inline void Test_1()
{
	int T, n, m;
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));	//存值数组归零 
		n = rdi(10, 100);
		m = rdi(0, n - 1);	//查询次数 
		Bitset b(n);
		for (int i = 0; i < m; i++)
		{
			int x = rdi(0, n - 1);
			b.set(x);
			a[x] = 1;
			c[i] = x;	//把测试数组保存起来 
		}

		int t = rdi(0, n);
		for (int i = 0; i < t; i++) {
			int x = rdi(0, n - 1);	//生成一个要检测的值
			if (a[x] != b[x])
			{
				cout << "WA: \n";
				cout << n << " " << m << " " << t << "\n";
				for (int j = 0; j <= i; j++)
					cout << c[i] << " ";
				cout << "\n" << x << "\n";
				return;
			}
		}
	}
	cout << "Accepted\n";
}

//测试count正确性
void Test_2()
{
	int T; cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));	//存值数组归零 
		int n = rdi(10, N - 100);
		int m = rdi(0, n - 1);
		Bitset b(n);
		for (int i = 0; i < m; i++)
		{
			int x = rdi(0, n - 1);
			b.set(x);
			a[x] = 1;
			c[i] = x;	//把测试数组保存起来 
		}

		int t = rdi(0, n);
		int res = 0;
		for (int i = 0; i < n; i++)
			if (a[i]) res++;
		if (res != b.count())
		{
			cout << "WA: \n";
			cout << n << " " << m << "\n";
			cout << res << " " << b.count() << "\n";
			for (int i = 0; i < m; i++)
				cout << c[i] << " ";
		}
	}
	cout << "Accepted\n";
}

//用于测试函数
void Test()
{
	int n, m;
	cin >> n >> m;
	Bitset b(n);
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		b.set(x);
	}
}

int main()
{
	//Test_1();
	Test_2();
	//Test();
	return 0;
}