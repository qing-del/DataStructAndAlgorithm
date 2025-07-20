// 测试链接：https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
// 滑动窗口 -- 至少 K 个重复字符的最长子串
#include <bits/stdc++.h>
using namespace std;

/*
思路：
题目只有26种字符 去跑一个函数：
    有 i 种字符的窗口中 每种字符数都>=k的 窗口最大长度是多少
*/
class Solution {
    int cnt[26];    //计数窗口内字符的数量
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 1, l, r, tk, debt; i <= 26; i++)
        {
            memset(cnt, 0, sizeof(cnt));
            l = 0, r = 0, tk = i, debt = k * i;

            //窗口：[l, r) 左闭右开
            while (r < n)
            {
                if (!cnt[s[r] - 'a']) tk--;
                if (cnt[s[r] - 'a'] < k) debt--;
                cnt[s[r] - 'a']++;
                r++;

                //种类超限开始收缩左边界
                while (tk < 0)
                {
                    cnt[s[l] - 'a']--;
                    if (!cnt[s[l] - 'a']) tk++;
                    if (cnt[s[l] - 'a'] < k) debt++;
                    l++;
                }

                if (!debt) ans = Max(ans, r - l);
            }
        }
        return ans;
    }
};

//输入：s = "ababbc", k = 2
int main() {
    Solution solution;
    string s = "ababbc";
    int k = 2;
    int result = solution.longestSubstring(s, k);
    cout << "The length of the longest substring with at least " << k << " repeating characters is: " << result << endl;
    return 0;
}