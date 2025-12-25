// n皇后问题 - 子集树遍历搜索版本
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pir pair<int, int>
#define mk(x,y) make_pair(x,y)
const int N = 15;

int n, ans;
vector<pir> queens; // 存储已放置的皇后位置

il bool check(int x, int y)
{
    for(auto queen : queens)
    {
        int qx = queen.first, qy = queen.second;
        if(qx == x || qy == y || abs(qx - x) == abs(qy - y))
            return false;
    }
    return true;
}

void dfs(int pos)
{
    if(pos > n * n) // 遍历完所有格子
    {
        if(queens.size() == n) // 放置了n个皇后
        {
            ans++;
            if(ans <= 3)
            {
                vector<int> cols(n+1, 0);
                for(auto queen : queens)
                    cols[queen.first] = queen.second;
                for(int i = 1; i <= n; i++)
                    cout << cols[i] << " ";
                cout << endl;
            }
        }
        return;
    }
    
    int x = (pos - 1) / n + 1;
    int y = (pos - 1) % n + 1;
    
    // 选择在当前格子放置皇后
    if(check(x, y))
    {
        queens.push_back(mk(x, y));
        dfs(pos + 1);
        queens.pop_back();
    }
    
    // 选择不在当前格子放置皇后
    dfs(pos + 1);
}

il int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    n = read();
    dfs(1);
    cout << ans << endl;
    return 0;
}