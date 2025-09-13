// 测试链接：https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
// 二分答案 - 第 k 小的数对距离
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0], ans = -1;
        while (l <= r)
        {
            int x = (l + r) >> 1;
            int cnt = 0;
            for (int ll = 0, rr = 0; ll < n; ll++)
            {
                while (rr < n - 1 && nums[rr + 1] - nums[ll] <= x)
                    rr++;
                cnt += rr - ll;
            }

            if (cnt < k)
                l = x + 1;
            else
                r = x - 1, ans = x;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,3,1};
    int k = 1;
    cout << Solution().smallestDistancePair(nums, k) << endl;
    return 0;
}