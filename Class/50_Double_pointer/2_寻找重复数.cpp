// 测试链接：https://leetcode.cn/problems/find-the-duplicate-number/
// 双指针 --- 寻找重复数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = 0;

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// 输入：nums = [1,3,4,2,2]
int main() {
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}