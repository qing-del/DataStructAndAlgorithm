// 测试链接：https://leetcode.cn/problems/first-missing-positive/
// 双指针 - 缺失的第一个正整数
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static void swap(int& a, int& b) { int temp = a; a = b; b = temp; }
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(r > l)
        {
            if(nums[l] == l + 1) l++;
            else if(nums[l] > r || nums[l] <= l || nums[nums[l] - 1] == nums[l])
            {
                swap(nums[l], nums[r - 1]);
                r--;
            }
            else
                swap(nums[l], nums[nums[l] - 1]);
        }
        return l + 1;
    }
};

int main(){
    vector<int> nums = {1, 2, 0};
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}