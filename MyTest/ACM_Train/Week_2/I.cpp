#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
	int num;
	int a;
	int b;
	int c;
	int sum;
};

bool compare(const student& a, const student& b)
{
	if (a.sum == b.sum)
		if (a.a == b.a)
			return a.num < b.num;
		else
			return a.a > b.a;

	return a.sum > b.sum;
}

int main()
{
	int n;
	cin >> n;
	vector<student> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		arr[i].num = i + 1;
		arr[i].sum = arr[i].a + arr[i].b + arr[i].c;
	}

	sort(arr.begin(), arr.end(), compare);

	int len = arr.size() > 5 ? 5 : arr.size();

	for (int i = 0; i < len; i++)
	{
		cout << arr[i].num << " " << arr[i].sum << endl;
	}
	

	return 0;
}