// 测试连接：https://leetcode.cn/problems/subarrays-with-k-different-integers/
// 滑动窗口 -- K个不同整数的子数组
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
思路：（AC 7ms 40.32MB）
设计一个f(nums, k)函数 --- 获取小于等于 k 的种数字的所有合法数组
就可以将题目的要求转化为：subarraysWithKDistinct = f(nums, k) - f(nums, k-1)
f 函数则是可以使用 滑动窗口来解决
*/
class Solution {
    const static int N = 2e4 + 10;
    int n, cnt[N];
    //获取小于等于 k 的种数字的所有合法数组
    int f(vector<int>& nums, int k)
    {
        memset(cnt, 0, sizeof(cnt));
        //区间是[l, r) 左开右闭
        int l = 0, r = 0, ans = 0;
        while (r < n)
        {
            if (!cnt[nums[r]]) k--;
            cnt[nums[r]]++;
            r++;

            while (k < 0)
            {
                cnt[nums[l]]--;
                if (!cnt[nums[l]]) k++;
                l++;
            }

            ans += r - l;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();
        return f(nums, k) - f(nums, k - 1);
    }
};

/*
我的思路：（AC 2821ms 40.34MB）
分析：
发现数组可以是重复的---示例1 可以看出来 所以可以直接使用一个变量来计算答案 不用使用set去重
同时要求子数组是连续的 可以考虑到是 滑动窗口
只要 滑动窗口内 只有 k 种数字就可以是一个合法的答案
--滑动窗口采用 [l, r) 左闭右开--
*/
class My_Solution {
    static const int N = 2e4 + 5;
    int cnt[N]; //计算这个值在窗口内出现的次数
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        memset(cnt, 0, sizeof(cnt));
        int ans = 0, type = 0, l = 0, r = 0;
        while (r < n)
        {
            //先判断下一个数能不能进入这个窗口
            if (cnt[nums[r]] == 0 && type == k)
            {
                //进入这条分支说明下一个数值是不可以加进来这个地方的
                //这个时候进行收缩区间的处理 直到下一个数值可以加进这个窗口
                while (type == k)
                {
                    cnt[nums[l]]--;
                    if (!cnt[nums[l]]) type--;
                    l++;
                }
            }
            else
            {
                //这条分支表示 下一个值可以进入窗口
                if (!cnt[nums[r]]) type++;
                cnt[nums[r]]++;
                r++;

                if (type == k)
                {
                    //这个时候尝试收缩左边界
                    int tl = l, ttype = type;
                    while (ttype == k)
                    {
                        ans++;
                        cnt[nums[tl]]--;
                        if (!cnt[nums[tl]]) ttype--;
                        tl++;
                    }
                    while (tl > l) cnt[nums[--tl]]++;
                }
            }
        }
        return ans;
    }
};

//输入：nums = [1,2,1,2,3], k = 2
// int main() {
//     Solution sol;
//     vector<int> nums = {1, 2, 1, 2, 3};
//     int k = 2;
//     cout << sol.subarraysWithKDistinct(nums, k) << endl; // 输出结果
//     return 0;
// }


//输入：nums = [1,2,1,3,4], k = 3
int main() { 
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 4};
    int k = 3;
    cout << sol.subarraysWithKDistinct(nums, k) << endl; // 输出结果
    return 0;
}