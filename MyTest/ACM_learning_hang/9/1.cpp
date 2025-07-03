#include <iostream>
#include <cstring>
using namespace std;
#define MAX 510

        //机器任务分配源码

int lN, rN;
int linker[MAX];
int g[MAX][MAX];	//邻接矩阵
bool used[MAX];		//右边是否匹配

bool dfs(int n);
int hungary();

int main()
{
	int k;
	while (cin >> lN && lN)
	{
		cin >> rN >> k;
		memset(g, 0, sizeof(g));
		int id, l, r;
		for (int i = 0; i < k; i++)
		{
			cin >> id >> l >> r;
			if (l != 0 && r != 0)
				g[l][r] = 1;
		}
		cout << hungary() << endl;
	}
	return 0;
}

int hungary()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int i = 0; i < lN; i++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(i)) res++;
	}
	return res;
}

bool dfs(int l)
{
	for (int r = 0; r < rN; r++)
	{
		if (g[l][r] && !used[r])
		{
			used[r] = 1;
			if (linker[r] == -1 || dfs(linker[r]))
			{
				linker[r] = l;
				return true;
			}
		}
	}
	return false;
}