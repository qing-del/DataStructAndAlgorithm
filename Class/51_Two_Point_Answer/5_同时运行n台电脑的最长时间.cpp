#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        ll sum = 0, ans = 0, maxn = 0;
        for(int i = 0; i < m; i++) {
            sum += batteries[i];
            maxn = maxn > batteries[i] ? maxn : batteries[i];
        }
        
        // 贪心（优化）（其实不加可以AC，速度慢一点）
        if (sum >= n * maxn) return sum / n;

        int l = 0, r = maxn;
        // 二分答案
        while(l<=r)
        {
            int x = (l+r)>>1, cnt = 0;
            ll tmp = 0;
            for(int i=0;i<m;i++) 
            {
                if(batteries[i]>=x) cnt++;
                else tmp += batteries[i];
            }

            if(tmp >= 1LL * (n-cnt) * x) 
                ans = x, l = x+1;
            else 
                r = x-1;
        }
        return ans;
    }
};