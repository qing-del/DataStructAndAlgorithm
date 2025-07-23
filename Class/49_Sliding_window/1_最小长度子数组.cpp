//测试连接：https://leetcode.cn/problems/minimum-size-subarray-sum/
// 滑动窗口 -- 最小长度子数组
#include <bits/stdc++.h>
using namespace std;
/* 
正统写法：
从第零位索引开始累加
直到sum大于等于target
下面要加个while循环（若是sum - arr[left] >= target）
循环内容：
    sum -= arr[left];
    left++;
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (right < n) {
            sum += nums[right++];
            while (sum >= target) {
                ans = min(ans, right - left);
                sum -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/* 
我的思路：
就是两个变量维护一个窗口的边界（滑动窗口）
窗口无限大的话就是sum无限大，然后窗口小的话，sum就会小
利用滑动窗口来check，然后进行二分答案
O（nlogn） ------ 会超时
 */
class Solution {
    const static int N = 1e5 + 10;
    int n, m;   // n为数组长度，m为目标和
    int pre[N];  // 前缀和数组（用于二分之后的起步运算）

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        n = nums.size();
        m = target;
        pre[0] = 0;

        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        int ans = n + 1;
        // 二分答案
        int left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) >> 1;
            for (int i = mid; i <= n; i++) {
                int sum = pre[i] - pre[i - mid];
                if (sum >= m) {
                    ans = min(ans, mid);
                    right = mid - 1;
                    break;
                }
                if (i == n) left = mid + 1;
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};

//输入：target = 7, nums = [2,3,1,2,4,3]
int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    Solution s;
    cout << s.minSubArrayLen(target, nums);
    return 0;
}