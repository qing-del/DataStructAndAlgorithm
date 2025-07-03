#include <bits/stdc++.h>
using namespace std;

//贪心
class Solution {
    int Max(const int& a, const int& b)
    {
        return a > b ? a : b;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = -INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum < 0 && ans != -INT_MAX) sum = 0;
            sum += nums[i];
            
            ans = Max(ans, sum);
        }
        return ans;
    }
};