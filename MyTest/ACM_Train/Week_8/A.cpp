#include <bits/stdc++.h>
using namespace std;
int T, x, n;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        int cnt = 0;
        map<int, int> m;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (m[x])
            {
                m[x] = 0;
                cnt++;
            }
            else
                m[x]++;
        }
        cout << cnt << endl;
    }
    return 0;
}