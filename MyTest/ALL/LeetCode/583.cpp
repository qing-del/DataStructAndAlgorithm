#include <bits/stdc++.h>
using namespace std;

//二维dp
class Solution {
    int dp[502];
    int Max(int a, int b) { return a > b ? a : b; }

public:
    int minDistance(string word1, string word2) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = word1.size(), m = word2.size();
        for (int i = 0; i <= m; i++)
            dp[i] = 0;

        for (int i = 1; i <= n; i++) {
            int pre = 0;
            for (int j = 1; j <= m; j++) {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre + 1;
                else
                    dp[j] = Max(dp[j - 1], dp[j]);
                
                pre=tmp;
            }
        }
        return (n+m)-(2*dp[m]);
    }
};