#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define rg register
#define sg string
const int N = 1e3 + 2;
vector<string> prg[N];
int n, t1, t2, t3, t4, t5, Q, p[N], al[30];

il void clear() {
	for (int i = 0; i <= n; i++)
		prg[i].clear();			//程序指令储存数组清空
	memset(p, 0, sizeof(p));	//指令条归零
	memset(al, 0, sizeof(al));
}

il void Init()
{
	cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
	rg sg input;
	rg int k = 1;
	cin.ignore();
	while (1)
	{
		getline(cin, input);
		prg[k].push_back(input);
		if (input == "end")
		{
			k++;
			if (k > n) return;
		}
	}
}

il bool check()
{
	for (int i = 1; i <= n; i++)
		if (p[i] != prg[i].size() - 1)
			return 0;
	return 1;
}

il void solve()
{
	deque<int> rq;
	queue<int> bq;
	vector<map<int, int>> mp(n + 1);	//独立访问变量的值的储存
	for (int i = 1; i <= n; i++)
		rq.push_back(i);
	rg int use = 0, pg = rq.front();
	rq.pop_front();
	rg bool locked = 0;
	while (1)
	{
		rg sg cur = prg[pg][p[pg]];

		if (rq.empty() && bq.empty() && cur == "end" && check()) break;


		if (cur.find("print", 0) != string::npos)
		{
			rg int var = cur[6] - 'a';
			cout << pg << ": " << al[var] << "\n";
			p[pg]++;
			use += t2;
		}
		else if (cur == "lock")
		{
			if (!locked)
			{
				locked = 1;
				use += t3;
				p[pg]++;
			}
			else
			{
				bq.push(pg);
				pg = rq.front();
				use = 0;
				rq.pop_front();
			}
		}
		else if (cur == "unlock")
		{
			if (!bq.empty())
			{
				rq.push_front(bq.front());
				bq.pop();
			}
			p[pg]++; use += t4;
			locked = 0;
		}
		else if (cur == "end")
		{
			pg = rq.front();
			use = 0;
			rq.pop_front();
		}
		else
		{
			istringstream cins(cur);
			rg char in1, in2; rg int num;
			cins >> in1 >> in2 >> num;
			rg int var = cur[0] - 'a';
			al[var] = num;
			use += t1; p[pg]++;
		}

		if (use >= Q && !rq.empty())
		{
			use = 0;
			rq.push_back(pg);
			pg = rq.front();
			rq.pop_front();
		}
		else if (use>=Q && rq.empty())
		{
			use = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	rg int T; cin >> T;
	while (T--)
	{
		clear();
		Init();
		solve();
		if (T != 0) cout << "\n";
	}
	return 0;
}