//from codeforces round 1028.div2
//链接：https://codeforces.com/contest/2116/problem/B
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N = 1e5 + 10;
const int P = 998244353;
int n, p[N], q[N], pw[N];
il void init()
{
    pw[0] = 1; pw[1] = 2;
    for (int i = 2; i < N; i++) pw[i] = (pw[i - 1] * 2) % P;
}

il int Max(int a, int b) { return a > b ? a : b; }

il void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    int ba = 0, bb = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > p[ba]) ba = i;
        if (q[i] > q[bb]) bb = i;

        int pba = i - ba;   //获取和 ba 互补的下标
        int pbb = i - bb;   //获取和 bb 互补的下标

        int id1 = Max(p[ba], q[pba]),
            id2 = Max(q[bb], p[pbb]);

        if (id1 > id2)
            id1 = p[ba], id2 = q[pba];
        else if (id1 < id2)
            id1 = q[bb], id2 = p[pbb];
        else
        {
            id1 = p[ba] + q[pba], id2 = q[bb] + p[pbb];
            if (id1 > id2) id1 = p[ba], id2 = q[pba];
            else id1 = q[bb], id2 = p[pbb];
        }

        cout << (pw[id1] + pw[id2]) % P << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init(); //初始化
    int t; cin >> t;
    while (t--) solve();
    return 0;
}