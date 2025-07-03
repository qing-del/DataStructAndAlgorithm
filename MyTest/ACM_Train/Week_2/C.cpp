#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	int a;
	int b;
	int c;
	int sum;
	int num;

	student()
	{
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->sum = 0;
		this->num = 0;
	}
};

bool compare(const student& a, const student& b)
{
	if (a.sum == b.sum) return a.num < b.num;
	return a.sum > b.sum;
}

int main()
{
	int N;
	cin >> N;
	vector<student> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].name;
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		arr[i].sum = arr[i].a + arr[i].b + arr[i].c;
		arr[i].num = i;
	}

	for (int i = 0, len = N - 1; i < len; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (abs(arr[i].sum - arr[j].sum) <= 10)			{
				if (abs(arr[i].a - arr[j].a) <= 5 && abs(arr[i].b - arr[j].b) <= 5 && abs(arr[i].c - arr[j].c) <= 5)
					cout << arr[i].name << " " << arr[j].name << endl;
			}
		}
	}
}