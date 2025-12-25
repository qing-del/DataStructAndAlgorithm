#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int qx[N], hx, tx;
int qi[N], hi, ti;
class Solution {
    static int Min(int a, int b) { return a < b ? a : b; }
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 1) return n;

        memset(qx, 0, sizeof(qx));
        hx = 0, tx = 0;
        memset(qi, 0, sizeof(qi));
        hi = 0, ti = 0;

        int ans = 0;

        for (int l = 0, r = 0; r < n; r++)
        {
            while (hx < tx && nums[r] > nums[qx[tx - 1]]) tx--;
            qx[tx++] = r;
            
            while (hi < ti && nums[r] < nums[qi[ti - 1]]) ti--;
            qi[ti++] = r;

            while (hx < tx && hi < ti && nums[qx[hx]] - nums[qi[hi]] > limit)
            {
                l = Min(qx[hx], qi[hi]) + 1;
                if (qx[hx] < l) hx++;
                else hi++;
            }

            ans = Max(ans, r - l + 1);

            if (qx[hx] < l) hx++;
            if (qi[hi] < l) hi++;
        }

        return ans;
    }
};