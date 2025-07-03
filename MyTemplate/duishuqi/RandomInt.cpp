#include <iostream>
#include <random>
using namespace std;

int rdi(int l, int r)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> distrib(l, r);
	return distrib(gen);
}

int main()
{
	int n, l, r;
	cin >> n >> l >> r;
    while (n--)
        cout<<rdi(l, r)<<" ";
    cout << "\n";
	return 0;
}