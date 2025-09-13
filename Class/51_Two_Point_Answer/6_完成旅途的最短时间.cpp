// 测试链接：https://leetcode.cn/problems/minimum-time-to-complete-trips/
// 二分答案 - 完成旅途的最短时间
#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size(), minn = 1e7 + 5;
        for(int i = 0; i < n; i++) minn = minn < time[i] ? minn : time[i];
        ll l = 0, r = (ll)totalTrips * minn, ans = 0;
        while(l <= r)
        {
            ll x = (l + r) >> 1;
            ll cnt = 0;
            for(int i = 0; i < n; i++) 
            {
                cnt += x / time[i];
                if(cnt >= totalTrips) break;    // 此时说明已经满足要求了
            }
            if(cnt >= totalTrips)
                ans = x, r = x - 1;
            else
                l = x + 1;
        }
        return ans;
    }
};