#include <bits/stdc++.h>
using namespace std;
#define il inline
#define endl '\n'
#define ll long long
const int N = 1e5 + 10;
int n, hp, cuts[N], poisons[N];

il bool check(int x)
{
	ll cnt = 0;
    for(int i = 0; i < n ; i++)
    {
        ll harm = 1LL * cuts[i] > 1LL * poisons[i] * (x - i - 1) ? 1LL * cuts[i] : 1LL * poisons[i] * (x - i - 1);
        cnt += harm;
        if(cnt >= hp) return true;    // 能把怪兽打败
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> hp;
    for(int i = 0; i < n; i++) cin >> cuts[i];
    for(int i = 0; i < n; i++) cin >> poisons[i];
    int l = 0, r = hp + 1, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}