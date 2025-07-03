#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 4;
int n, a, b, v[N], ans;
bitset<N> used;

void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    used[a] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first == b)
        {
            ans = p.second;
            return;
        }
        if (p.first - v[p.first] > 0 && !used[p.first - v[p.first]])
        {
            q.push(make_pair(p.first - v[p.first], p.second + 1));
            used[p.first - v[p.first]] = 1;
        }
        if (p.first + v[p.first] <= n && !used[p.first + v[p.first]])
        {
            q.push(make_pair(p.first + v[p.first], p.second + 1));
            used[p.first + v[p.first]] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    ans = -1;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    bfs();
    cout << ans << endl;
    return 0;
}