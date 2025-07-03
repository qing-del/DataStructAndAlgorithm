#include <bits/stdc++.h>
using namespace std;

//线性dp
class Solution {
    int Max(const int& a, const int& b) { return a > b ? a : b; }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[j] > nums[i])
                    dp[j] = Max(dp[j], dp[i] + 1);
        int ans = 0;
        for (int val : dp)
            ans = Max(val, ans);
        return ans;
    }
};