#include <iostream>
using namespace std;
#include <cstring>
#include <bitset>
#include <queue>
const int M = 1e2 + 4, N = 1e3 + 4;
int m, n, a[M][M], x, y, c, pay;
bool arrive;
bitset<M> used[M];

int x_i[] = { 0,0,-1,1 };
int y_j[] = { -1,1,0,0 };

int Max(const int& a, const int& b) { return a > b ? a : b; }
int Min(const int& a, const int& b) { return a < b ? a : b; }

void bfs(int i, int j, int cost)
{
    if (i == m && j == m)
    {
        if (!arrive)
        {
            pay = cost;
            arrive = 1;
            return;
        }
        else
        {
            pay = Min(pay, cost);
            return;
        }
    }

    for (int k = 0; k < 4; k++)
    {
        int i0 = i + x_i[k];
        int j0 = j + y_j[k];
        if (used[i0][j0]) continue;
        if (i0 <= 0 || j0 <= 0 || i0 > m || j0 > m)
            continue;
        if (a[i][j] < 0)
        {
            if (a[i0][j0] == -1)
                continue;
            else
            {
                int temp = a[i][j];
                if (a[i0][j0] == -a[i][j])
                {
                    a[i][j] = -1;
                    used[i0].set(j0);
                    bfs(i0, j0, cost);
                    used[i0].reset(j0);
                    a[i][j] = temp;
                }
                else
                {
                    a[i][j] = -1;
                    used[i0].set(j0);
                    bfs(i0, j0, cost + 1);
                    used[i0].reset(j0);
                    a[i][j] = temp;
                }
            }
        }
        else
        {
            if (a[i0][j0] == a[i][j])
            {
                used[i0].set(j0);
                bfs(i0, j0, cost);
                used[i0].reset(j0);
            }
            else if (a[i0][j0] != -1)
            {
                used[i0].set(j0);
                bfs(i0, j0, cost + 1);
                used[i0].reset(j0);
            }
            else
            {
                used[i0].set(j0);
                bfs(i0, j0, cost + 2);
                used[i0].reset(j0);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, -1, sizeof(a));
    cin >> m >> n;

    if (n < m - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> c;
        a[x][y] = c;
    }

    used[1].set(1);
    bfs(1, 1, 0);

    if (arrive)
        cout << pay << endl;
    else
        cout << -1 << endl;

    return 0;
}