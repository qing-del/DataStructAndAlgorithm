#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int k, x; cin >> k >> x;
        int ans;
        for (int i = 1; i <= k; i++)
        {
            if ((x - 1) % 3 == 0 && (x - 1) / 3 != 0 && i == k)
                x = (x - 1) / 3;
            else x <<= 1;
        }
        cout << x << '\n';
    }
    return 0;
}