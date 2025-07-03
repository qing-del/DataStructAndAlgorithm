#include <iostream>
#include <stack>
using namespace std;
const int MAX = 3e6 + 5;
int a[MAX], ans[MAX];
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = n; i > 0; i--)
	{
		while (!s.empty() && a[i] >= a[s.top()])s.pop();
		ans[i] = s.empty() ? 0 : s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}