// 测试链接：https://leetcode.cn/problems/split-array-largest-sum/
// 二分答案 - 分割数组的最大值
#include  <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); i++)
            l = l > nums[i] ? l : nums[i],
            r += nums[i];

        int ans = r;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int tmp = 0, z = 1;
            for (int i = 0; i W< nums.size();)
            {
                if (tmp + nums[i] <= mid) tmp += nums[i++];
                else tmp = nums[i++], z++;
            }

            if (z <= k)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    Solution s;
    cout << s.splitArray(nums, k) << endl;
    return 0;
}