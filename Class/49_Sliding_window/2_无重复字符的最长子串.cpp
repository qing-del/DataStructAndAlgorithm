//测试连接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
// 滑动窗口 -- 无重复字符的最长子串
#include <bits/stdc++.h>
using namespace std;

// 左程云的正解思路，相当于优化了空间复杂度，将哈希表换成了数组
// 由于字符集是ASCII码，所以可以用一个长度为256的数组来记录
class Solution {
    int a[256]; // 用于记录字符出现的次数

    static int Max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int lengthOfLongestSubstring(string s) {
        memset(a, 0, sizeof(a)); // 初始化数组
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.size()) {
            // 先检测下一个字符加入窗口之后是否会出现重复字符
            while (a[s[right]] > 0) {
                a[s[left]]--;
                left++;
            }
            a[s[right]]++;
            ans = Max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};


/* 我的思路：AC
创建一个滑动窗口，窗口内无重复的字符，则更新最大长度
然后用双指针维护窗口的边界
如果窗口内有重复字符，则移动左指针，直到窗口内无重复字符
用一个哈希表用于记录窗口内字符的出现次数
时间复杂度 O(n)
 */
class My_Solution {
    static int Max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int left = 0, right = 0;
        int ans = 0;
        while(right < s.size()) {
            //先检测下一个字符加入窗口之后是否会出现重复字符
            while(m[s[right]] > 0) {
                m[s[left]]--;
                left++;
            }
            m[s[right]]++;
            ans = Max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

// 输入: s = "abcabcbb"
int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}