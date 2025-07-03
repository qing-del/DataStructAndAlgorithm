//题目链接：https://vjudge.net/problem/POJ-1475#author=GPT_zh
//推箱子
//属于嵌套搜索题

#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define uint unsigned int
#define il inline
#define rg register

const int N = 22;
int n, m, bi, bj, pi, pj, ei, ej;
char mp[N][N];
bool bvis[N][N], pvis[N][N];
string ansPath;
int ni[] = { 0,0,1,-1 }, nj[] = { 1,-1,0,0 };
string pff[] = { "e","w","s","n" }, bff[] = { "E","W","S","N" };

struct person {
	int i, j, cost;
	string path;
	person(int i = 0, int j = 0, string path = "", int cost = 0)
	{
		this->i = i;
		this->j = j;
		this->path = path;
		this->cost = cost;
	}
	bool operator<(const person& x) const
	{
		return cost > x.cost;
	}
};

il int ABS(int a, int b) {
	return a > b ? a - b : b - a;
}

struct box {
	int i, j, cost;
	int li, lj;
	string path;
	box(int i = 0, int j = 0, string path = "", int li = 0, int lj = 0, int cost = 0)
	{
		this->i = i;
		this->j = j;
		this->li = li;
		this->lj = lj;
		this->path = path;
		this->cost = ABS(i, ei) + ABS(j, ej);
	}
	bool operator<(const box& x) const
	{
		return cost > x.cost;
	}
};

il string toString(int x) {
	ostringstream oss;
	oss << x;
	return oss.str();
}

person tmpPerson;		//用于两个函数转移值的 
il bool bfs2(int dei, int dej, int psi, int psj, int bani, int banj)	//人的bfs 
{
	if (psi == dei && psj == dej)
	{
		tmpPerson = person(psi, psj, "");
		return 1;
	}
	ms(pvis, 0);
	priority_queue<person> q;
	q.push(person(psi, psj, "", ABS(psi, dei) + ABS(psj, dej)));
	while (q.size())
	{
		person pos = q.top(); q.pop();
		rg int ui = pos.i, uj = pos.j;
		if (pvis[ui][uj]) continue;
		pvis[ui][uj] = 1;

		for (int k = 0; k < 4; k++)
		{
			rg int vi = ui + ni[k], vj = uj + nj[k];
			if (vi<1 || vj<1 || vi>n || vj>m || pvis[vi][vj] || mp[vi][vj] == '#' || (bani==vi && banj==vj)) continue;
			if (vi == dei && vj == dej)	//抵达的是要推的位置 
			{
				pos.path += pff[k];
				tmpPerson = pos;
				return 1;
			}

			q.push(person(vi, vj, pos.path + pff[k], ABS(vi, dei) + ABS(vj, dej)));
		}
	}
	return 0;
}

il bool bfs1()	//箱子的bfs 
{
	ms(bvis, 0);
	priority_queue<box> q;
	q.push(box(bi, bj, "", pi, pj));	//初始箱子位置没有人的前一个位置 
	while (q.size())
	{
		box pos = q.top(); q.pop();
		rg int ui = pos.i, uj = pos.j;
		if (bvis[ui][uj]) continue;
		bvis[ui][uj] = 1;

		for (int k = 0; k < 4; k++)
		{
			rg int vi = ui + ni[k], vj = uj + nj[k];
			rg int pui = ui - ni[k], puj = uj - nj[k];	//推箱子人需要达到的位置 
			if (vi<1 || vj<1 || vi>n || vj>m || bvis[vi][vj] || mp[vi][vj] == '#' || pui<1 || puj<1 || pui>n || puj>m || mp[pui][puj] == '#') continue;

			if (bfs2(pui, puj, pos.li, pos.lj, ui, uj))
			{
				if (vi == ei && vj == ej)
				{
					ansPath = pos.path + tmpPerson.path + bff[k];
					return 1;
				}
				rg int li = ui, lj = uj;			//人若是推了 就要更新人的位置为箱子之前的位置 
				rg string lpath = pos.path + tmpPerson.path;	//这时候的移动还没算上推了之后的
				q.push(box(vi, vj, lpath + bff[k], li, lj));

			}
		}
	}
	return 0;
}

int main()
{
	IOS_IO;
	rg int T = 0;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		++T;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> mp[i][j];
				if (mp[i][j] == 'T') ei = i, ej = j;
				if (mp[i][j] == 'B') bi = i, bj = j;
				if (mp[i][j] == 'S') pi = i, pj = j;	//仅记录最初的位置 后续不改变 
			}
		if (bfs1())
			cout << "Maze #" << T << "\n" << ansPath << "\n";
		else
			cout << "Maze #" << T << "\nImpossible.\n";
	}
	return 0;
}