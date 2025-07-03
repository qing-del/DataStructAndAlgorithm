#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	vector<int> line;
	int val = 0;
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<Node> arr(n+1);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[a].line.push_back(b);
			arr[b].line.push_back(a);
		}

		int q;
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int cmd;
			cin >> cmd;
			if (cmd == 0)
			{
				int u, v;
				cin >> u >> v;
				arr[u].val += v;
			}
			else
			{
				int sum = 0;
				int u;
				cin >> u;
				for (auto it = arr[u].line.begin(); it != arr[u].line.end(); it++)
				{

					sum += arr[*it].val;
				}
				cout << sum << endl;
			}
		}
	}
	
	return 0;
}