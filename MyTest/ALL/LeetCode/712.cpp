class Solution {
    int Min(int a, int b) { return a < b ? a : b; }
public:
    int minimumDeleteSum(string s1, string s2) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int dp[1001]{};
        int n = s1.size(), m = s2.size();

        for (int i = 0; i <= n; i++)
        {
            int pre = dp[0];
            for (int j = 0; j <= m; j++)
            {
                int tmp = dp[j];
                if (!i && !j) dp[j] = 0;
                else if (i && !j) dp[j] += (int)s1[i - 1];
                else if (!i && j) dp[j] = dp[j - 1] + (int)s2[j - 1];
                else
                    if (s1[i - 1] == s2[j - 1])
                        dp[j] = pre;
                    else
                        dp[j] = Min(dp[j - 1] + s2[j - 1], dp[j] + s1[i - 1]);

                pre = tmp;
            }
        }

        return dp[m];
    }
};