#include <iostream>
using namespace std;
#include <bitset>
const int N = 1e2 + 5;
int high[N][N], R, C, mh[N][N], maxV, max_i, max_j;
bitset<N> bit[N];

int x[] = { 0,0,-1,1 };
int y[] = { -1,1,0,0 };

int Max(const int& a, const int& b) { return a > b ? a : b; }

int dfs(int i, int j)
{
    if (i < 0 || j < 0 || i >= R || j >= C)
        return 0;
    if (mh[i][j] != 0) return mh[i][j];
    mh[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x1 = i + x[k];
        int y1 = j + y[k];
        if (x1 < 0 || y1 < 0 || x1 >= R || y1 >= C) continue;
        if (high[i][j] > high[x1][y1] && bit[x1][y1] == 0)
        {
            bit[x1].set(y1);
            mh[i][j] = Max(mh[i][j], dfs(x1, y1) + 1);
            bit[x1].reset(y1);//回溯
        }
    }
    maxV = Max(maxV, mh[i][j]);
    return mh[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> high[i][j];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            maxV = Max(maxV, dfs(i, j));
    
    cout << maxV << endl;
    return 0;
}