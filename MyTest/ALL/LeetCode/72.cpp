#include <bits/stdc++.h>
using namespace std;

//二维dp
class Solution {
    int Max(int a, int b, int c) {
        int ans=a>b?a:b;
        return ans>c?ans:b;
    }

    int Min(int a, int b, int c) {
        int ans=a<b?a:b;
        return ans<c?ans:c;
    }

    public:
        int minDistance(string word1, string word2) {
            ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
            int n=word1.size(),m=word2.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));

            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    if(!i||!j) d[i][j]=i+j;
                    else if(word1[i-1]==word2[j-1])
                        dp[i][j]=Min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]);
                    else
                        dp[i][j]=1+Min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
            
            return dp[n][m];
        }
    };