#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long p[N];
int qi[N], hi, ti;
class Solution {
    static int Max(int a, int b) { return a > b ? a : b; }
    static int Min(int a, int b) { return a < b ? a : b; }
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0] >= k ? 1 : -1;
        memset(qi, 0, sizeof(qi));
        hi = 0, ti = 0;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] + nums[i - 1];
        int ans = N;
        for (int r = 0; r <= n; r++)
        {
            while (hi < ti && p[qi[ti - 1]] >= p[r]) ti--;
            qi[ti++] = r;

            while (hi < ti && p[r] - p[qi[hi]] >= k)
                ans = Min(ans, r - qi[hi++]);
        }
        return ans == N ? -1 : ans;
    }
};