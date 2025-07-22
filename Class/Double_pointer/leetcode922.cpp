// 测试链接：https://leetcode.cn/problems/sort-array-by-parity-ii/
// 双指针 -- 按奇偶排序数组 II
#include <bits/stdc++.h>
using namespace std;

/*
思路：
题目要求是将所有数字归位 奇数位是奇数，偶数位是偶数

暴力：
开辟两个数组 分别为奇偶 遍历一次 nums 将奇数和偶数分别放入奇偶两个数组中
然后遍历数组安排位置即可

优化：（AC 0ms 25.5MB）
题目信息中说：奇偶各占一半
会发现 只要是奇偶之间 其中一个满足了题意 那么 另一半就会已经归位好了
这个时候就可以使用双指针优化
*/
class Solution {
    void swap(int& a, int& b) 
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size(), odd = 1, even = 0;
        int last = n - 1;   //尾部指针
        while (odd < n && even < n)
        {
            if (nums[last] % 2)
            {
                //这个是奇数
                swap(nums[odd], nums[last]);
                odd += 2;
            }
            else
            {
                //这个是偶数
                swap(nums[even], nums[last]);
                even += 2;
            }
        }
        return nums;
    }
};

// 输入：nums = [4,2,5,7]
int main() {
    Solution sol;
    vector<int> nums = {4,2,5,7};
    vector<int> result = sol.sortArrayByParityII(nums);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}