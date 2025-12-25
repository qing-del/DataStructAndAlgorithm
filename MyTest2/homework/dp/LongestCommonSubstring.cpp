#include <bits/stdc++.h>
using namespace std;

class Solution {
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if (n == 1 && m == 1) return text1[0] == text2[0];
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int pre = 0, tmp;
            for (int j = 1; j <= m; j++)
            {
                tmp = dp[j];
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = pre + 1;
                else
                    dp[j] = Max(dp[j], dp[j - 1]);
                pre = tmp;
            }
        }
        return dp[m];
    }
};