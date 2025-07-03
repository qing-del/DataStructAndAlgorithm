#include <bits/stdc++.h>
using namespace std;

//二维dp
class Solution {
    int Max(const int& a, const int& b) { return a > b ? a : b; }

public:
    int longestCommonSubsequence(string text1, string text2) {
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[text1.size()][text2.size()];
    }
};