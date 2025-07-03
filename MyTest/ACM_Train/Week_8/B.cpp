#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 3;
int n, m, a[N][N], b[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] + b[i][j] << " ";
        cout << endl;
    }
    return 0;
}