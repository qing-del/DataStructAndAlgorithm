#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pir pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
const int N = 2e5 + 10;
int n, d[N], low[N], high[N];
pir h[N];
bool possible;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> d[i];
        for (int i = 1; i <= n; ++i) {
            int l, r;
            cin >> l >> r;
            h[i] = { l, r };
        }
        
        possible=1;
        low[0] = high[0] = 0;
        for (int i = 1; i <= n; ++i) {
            pir hi = h[i];
            if (d[i] != -1) {
                int step = d[i];
                int nl = low[i - 1] + step;
                int nh = high[i - 1] + step;
                nl = max(nl, hi.first);
                nh = min(nh, hi.second);
                if (nl > nh) {
                    possible = 0;
                    break;
                }
                low[i] = nl;
                high[i] = nh;
            }
            else {
                int nl = low[i - 1];
                int nh = high[i - 1] + 1;
                nl = max(nl, hi.first);
                nh = min(nh, hi.second);
                if (nl > nh) {
                    possible = 0;
                    break;
                }
                low[i] = nl;
                high[i] = nh;
            }
        }

        if (!possible) {
            cout << "-1\n";
            continue;
        }

        int ch = high[n];
        for (int i = n; i >= 1; --i) {
            if (d[i] != -1) {
                ch -= d[i];
                if (ch < low[i - 1] || ch > high[i - 1]) {
                    possible = 0;
                    break;
                }
            }
            else {
                int prev_h = ch - 1;
                if (prev_h >= low[i - 1] && prev_h <= high[i - 1]) {
                    d[i] = 1;
                    ch = prev_h;
                }
                else {
                    d[i] = 0;
                    if (ch < low[i - 1] || ch > high[i - 1]) {
                        possible = 0;
                        break;
                    }
                }
            }
        }

        if (ch != 0) possible = 0;

        if (!possible) {
            cout << "-1\n";
        }
        else {
            for (int i = 1; i <= n; ++i) cout << d[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}