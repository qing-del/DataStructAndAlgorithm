// 测试链接 : https://leetcode.cn/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 10;
int n, m;
bool vis[N][N], live[N][N];
class Solution {
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = 1;
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] != 'X') dfs(0, i, board);
            if (board[n - 1][i] != 'X') dfs(n - 1, i, board);
        }

        for (int i = 1, len = n - 1; i < len; i++)
        {
            if (board[i][m - 1] != 'X') dfs(i, m - 1, board);
            if (board[i][0] != 'X') dfs(i, 0, board);
        }

        for (int i = 1, lenn = n - 1; i < lenn; i++)
            for (int j = 1, lenm = m - 1; j < lenm; j++)
                if (!vis[i][j]) board[i][j] = 'X';
    }
};