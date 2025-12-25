// 测试链接：https://leetcode.cn/problems/container-with-most-water/
// 双指针 --- 盛最多水的容器
#include <bits/stdc++.h>
using namespace std;

class Solution {
    inline static int Max(int a, int b) { return a > b ? a : b; }
    inline static int Min(int a, int b) { return a < b ? a : b; }
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0, d;
        while (l < r)
        {
            d = r - l;
            ans = Max(ans, Min(height[l], height[r]) * d);
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};

// 输入：height = [1,8,6,2,5,4,8,3,7]
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}