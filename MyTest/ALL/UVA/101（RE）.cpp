#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define Str string
const int N = 30;
vector<int> a[N];		
unordered_map<int, int> hp;	//记录方块所在的块推编号
int n;

void Init()
{
	for (int i = 0; i <= n; i++)
	{
		a[i].clear();
		a[i].push_back(i);
		hp[i] = i;
	}
}

void moveAll(int p, int h, int q)	//将 p 堆块高度高于 h 的方块移动到 q 堆块上方
{
	for (int i = h; i < a[p].size(); i++)
	{
		int k = a[p][i];
		a[q].push_back(k);
		hp[k] = q;
	}
	a[p].resize(h);
}

void goBack(int p, int h)	//将 p 堆块高度大于 h 的归位
{
	for (int i = h + 1; i < a[p].size(); i++)
	{
		int k = a[p][i];
		a[k].push_back(k);
		hp[k] = k;
	}
	a[p].resize(h + 1);
}

int getHigh(int p)		//得到 p 号方块所处于堆块的高度
{
	int q = hp[p];
	for (int i = 0; i < a[q].size(); i++)
		if (a[q][i] == p)
			return i;
	return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	Str s1, s2; int num1, num2;
	cin >> n;
	Init();			//初始化
	while (cin >> s1)
	{
		if (s1 == "quit") break;
		cin >> num1 >> s2 >> num2;
		if (num1 == num2 || hp[num1] == hp[num2]) continue;
		if (s1 == "move" && s2 == "onto")
		{
			int h = getHigh(num1);
			goBack(num1, h);
			goBack(num2, getHigh(num2));
			a[hp[num2]].push_back(num1);
			a[hp[num1]].resize(h);
			hp[num1] = hp[num2];
		}
		else if (s1 == "move")
		{
			int h = getHigh(num1);
			goBack(num1, h);
			a[hp[num2]].push_back(num1);
			a[hp[num1]].resize(h);
			hp[num1] = hp[num2];
		}
		else if (s2 == "onto")
		{
			int h = getHigh(num1);
			goBack(num2, getHigh(num2));
			moveAll(hp[num1], h, hp[num2]);
			hp[num1] = hp[num2];
		}
		else
		{
			int h = getHigh(num1);
			moveAll(hp[num1], h, hp[num2]);
			hp[num1] = hp[num2];
		}
	}


	for (int i = 0; i < n; i++)
	{
		cout << i << ": ";
		if (a[i].empty())
			cout << "\n";
		else
			for (int j = 0; j < a[i].size(); j++)
				cout << a[i][j] << " ";
		cout << "\n";
	}
		
	return 0;
}