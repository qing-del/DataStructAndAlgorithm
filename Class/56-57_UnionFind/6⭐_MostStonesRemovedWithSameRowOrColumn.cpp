// 测试链接 : https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int f[N], ans;
class Solution {
    static int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    static void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) f[fb] = fa, ans++;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        ans = 0;
        map<int, int> cx, cy;
        for (int i = 0; i < n; i++) f[i] = i;
        for (int i = 0; i < n; i++)
        {
            if (cx.count(stones[i][0]))
                merge(cx[stones[i][0]], i);
            else
                cx[stones[i][0]] = i;

            if (cy.count(stones[i][1]))
                merge(cy[stones[i][1]], i);
            else
                cy[stones[i][1]] = i;
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> stones = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
    cout << Solution().removeStones(stones) << endl;
    return 0;
}