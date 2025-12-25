// 测试链接：https://leetcode.cn/problems/count-submatrices-with-all-ones/
// 单调栈 - 统计子矩阵元素全为 1 的个数
#include <bits/stdc++.h>
using namespace std;

const int N = 160;
int p[N], s[N], t;
class Solution {
    static int Min(int a, int b) { return a < b ? a : b; }
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == m && n == 1) return mat[0][0];
        memset(p, 0, sizeof(p));
        int ans = 0;
        for (int l = 0, left, len, bottom, cur, i; l < n; l++)
        {
            t = 0;
            for (i = 0; i < m; i++)
                p[i] = mat[l][i] ? p[i] + 1 : 0;

            for (i = 0; i < m; i++)
            {
                while (t > 0 && p[s[t]] >= p[i])
                {
                    cur = s[t--];
                    if (p[cur] > p[i])
                    {
                        left = !t ? -1 : s[t];
                        len = i - left - 1;
                        bottom = Max(left == -1 ? 0 : p[left], p[i]);
                        ans += ((len * (len + 1)) >> 1) * (p[cur] - bottom);
                    }
                }
                s[++t] = i;
            }

            
            while (t)
            {
                cur = s[t--];
                left = !t ? -1 : s[t];
                len = m - left - 1;
                bottom = left == -1 ? 0 : p[left];
                ans += ((len * (len + 1)) >> 1) * (p[cur] - bottom);
            }
        }
        return ans;
    }
};

// 错的奇奇怪怪，改对也奇奇怪怪
class My_Solution {
    static int Min(int a, int b) { return a < b ? a : b; }
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == m && n == 1) return mat[0][0];
        memset(p, 0, sizeof(p));
        int ans = 0;
        for (int l = 0, i; l < n; l++)
        {
            t = 0;
            for (i = 0; i < m; i++)
                p[i] = mat[l][i] ? p[i] + 1 : 0;

            for (i = 0; i < m; i++)
            {
                while (t && p[s[t]] >= p[i])
                {
                    int cur = s[t--];
                    if (p[cur] > p[i])
                    {
                        int h = p[cur] - Max(p[i], t == 0 ? 0 : p[s[t]]);
                        int len = i - 1 - (!t ? -1 : s[t]); // 就在这里（已修正）
                        ans += ((len * (len + 1)) >> 1) * h;
                    }
                }
                s[++t] = i;
            }

            while (t)
            {
                int cur = s[t--];
                int h = p[cur] - (t == 0 ? 0 : p[s[t]]);
                int len = m - (!t ? -1 : s[t]) - 1; // 就在这里（已修正）
                ans += ((len * (len + 1)) >> 1) * h;
            }
        }
        return ans;
    }
};

int main()
{
//    vector<vector<int>> arr = { {0,1,1,0}, {0,1,1,1}, {1,1,1,0} };
    vector<vector<int>> arr = { {1,0,1}, {1,1,0}, {1,1,0} };
    cout << Solution().numSubmat(arr) << endl;
    return 0;
}