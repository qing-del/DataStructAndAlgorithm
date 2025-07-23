//测试链接：https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
// 滑动窗口 -- 替换子串使得字符串平衡
#include <bits/stdc++.h>
using namespace std;

/*
思路：
大体可以看作 “最小覆盖子串” 的变形
以这个 s = "WWEQERQWQWWRWWERQWEQ" 来说
其中 Q=5，W=8，E=4，R=3  存在有3个W是不需要的，E和R是缺的
所以需要找到一个子串 同时覆盖有 3个 W的最短子串
*/
class Solution {
    int cnt[256];
    int getVal(const int& num, const int& len) { return num > len ? num - len : 0; }
    int Min(const int& a, const int& b) { return a < b ? a : b; }
public:
    int balancedString(string s) {
        int n = s.size();
        memset(cnt, 0, sizeof(cnt));
        int debt = 0, len = n >> 2;
        for (int i = 0; i < n; i++) cnt[s[i]]++;
       
        cnt['Q'] -= len;
        cnt['W'] -= len;
        cnt['E'] -= len;
        cnt['R'] -= len;

        debt += cnt['Q'] > 0 ? cnt['Q'] : 0;
        debt += cnt['W'] > 0 ? cnt['W'] : 0;
        debt += cnt['E'] > 0 ? cnt['E'] : 0;
        debt += cnt['R'] > 0 ? cnt['R'] : 0;

        if (!debt) return 0;

        int ans = INT_MAX, l = 0, r = 0;
        while (r < n)
        {
            //窗口尝试向右开始扩展
            if (cnt[s[r]] > 0) debt--;
            cnt[s[r]]--;
            r++;

            //若是满足题目要求时 收缩左边界
            while (!debt)
            {
                //记录答案
                ans = Min(ans, r - l);

                //尝试收缩左边界
                if (cnt[s[l]] >= 0) debt++;
                cnt[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};

/*
我的思路：（WA）hack: s="WWEQERQWQWWRWWERQWEQ" corret_ans = 4
1.统计四个字符所出现的次数
2.将所有的 数值达到 n/4 的差值都累加起来 sum
3.ans = sum / 2

错因：题目说的是替换子串的最小长度  这里计算的是单一替换字符的最少次数
PS:我并没有想到解法
*/
class My_Solution {
    int cnt[4];
    static int abs(int a, int b) { return a > b ? a - b : b - a; }
public:
    int balancedString(string s) {
        int n = s.size();
        memset(cnt, 0, sizeof(cnt));
        map<char, int> c;
        c['Q'] = 0, c['W'] = 1, c['E'] = 2, c['R'] = 3;
        for (int i = 0; i < s.size(); i++) cnt[c[s[i]]]++;
        int sum = 0;
        for (int i = 0, len = n >> 2; i < 4; i++)
            sum += abs(cnt[i], len);
        return (sum >> 1);
    }
};

// 输入：s = "QQQW"
int main() {
    Solution sol;
    string s = "QQQW";
    cout << sol.balancedString(s) << endl; // 输出：1
    return 0;
}