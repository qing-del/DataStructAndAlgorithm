//测试链接：https://leetcode.cn/problems/minimum-window-substring/
// 滑动窗口 -- 最小覆盖子串
#include <bits/stdc++.h>
using namespace std;

/* 正确写法：（AC 0ms 11.4MB）
使用负债的写法
常数优化更好
 */
class Solution {
    int cnt[256], debt;

    static int Min(int a, int b) {
        return a < b ? a : b;
    }

public:
    string minWindow(string s, string t) {
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i < t.size(); i++) {
            cnt[t[i]]--;
            debt++;
        }

        int ans = INT_MAX;
        int l=0,r=0;
        int start;
        while(r < s.size()) {
            cnt[s[r]]++;
            if(cnt[s[r]] <= 0) debt--;
            // 当窗口满足条件时，尝试收缩左边界
            while(l <= r && debt == 0) {
                if(ans > r-l+1){
                    ans = r-l+1;
                    start = l;
                }
                cnt[s[l]]--;
                if(cnt[s[l]] < 0) debt++;
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};

/* 我的思路：（AC 95ms 12.2MB）
开一个数组，记录t中每个字符出现的次数
开另一个数组，记录窗口中每个字符出现的次数
 */
class My_Solution {
    int a[256]; // 用于记录t中字符出现的次数
    int b[256]; // 用于记录窗口中字符出现的次数

    static int Min(int a, int b) {
        return a < b ? a : b;
    }

    // 检查窗口是否满足条件（字符串中只包含大小写英文字母）
    // 所以只需要遍历到 122
    bool check() {
        for(int i = 0; i < 123; i++) {
            // 如果窗口中字符出现次数小于t中字符出现次数，则返回false
            if(a[i] > b[i]) return 0;
        }
        return 1; // 否则返回true
    }

public:
    string minWindow(string s, string t) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        //先初始化 a 数组
        for(int i = 0; i < t.size(); i++) a[t[i]]++;
        int left = 0, right = 0;
        int ans = INT_MAX, ansL, ansR;
        while(right < s.size()) {
            b[s[right]]++;
            while(check()) {
                if(right - left + 1 < ans) {
                    ans = right - left + 1;
                    ansL = left;
                    ansR = right;
                }
                b[s[left]]--;
                left++;
            }
            right++;
        }
        return ans == INT_MAX ? "" : s.substr(ansL, ansR - ansL + 1);
    }
};

//输入：s = "ADOBECODEBANC", t = "ABC"
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl; // 输出 "BANC"
    return 0;
}