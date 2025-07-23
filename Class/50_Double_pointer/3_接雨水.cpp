// 测试链接：https://leetcode.cn/problems/trapping-rain-water/
// 双指针 --- 接雨水
#include <bits/stdc++.h>
using namespace std;

/*
第三种解法（拓展）：单调栈（后续补充）
空间复杂度 O(n) 复杂度
*/
class Solution {
public:
    int trap(vector<int>& height) {
        
    }
};

/*
第二种解法：双指针
空间优化更好 额外空间为 O(1) 复杂度
*/
class Solution_2 {
    static int Max(int a, int b) { return a > b ? a : b; }
    static int Min(int a, int b) { return a < b ? a : b; }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, l = 1, r = n - 2, lmax = height[0], rmax = height[n - 1];
        while (l <= r)
        {
            if (lmax > rmax)
            {
                //说明此时限制来自右边
                ans += Max(0, rmax - height[r]);
                rmax = Max(rmax, height[r--]);
            }
            else
            {
                ans += Max(0, lmax - height[l]);
                lmax = Max(lmax, height[l++]);
            }
        }
        return ans;
    }
};
// 第一种解法：使用辅助数组
class Solution_1 {
    static const int N = 2e4 + 10;
    int lmax[N], rmax[N];
    static int Max(int a, int b) { return a > b ? a : b; }
    static int Min(int a, int b) { return a < b ? a : b; }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        memset(lmax, 0, sizeof(lmax));
        memset(rmax, 0, sizeof(rmax));

        lmax[0] = height[0], rmax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) 
            lmax[i] = Max(lmax[i - 1], height[i]);
        for (int i = n-1; i > 0; i--) 
            rmax[i - 1] = Max(rmax[i], height[i - 1]);

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += Max(0, Min(lmax[i], rmax[i]) - height[i]);
        return ans;
    }
};

// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}