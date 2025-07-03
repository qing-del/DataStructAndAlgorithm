#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 3;
int n, m, k, a[N][N], b[N][N], c[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            for (int v = 1; v <= m; v++)
                c[i][j] += a[i][v] * b[v][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}