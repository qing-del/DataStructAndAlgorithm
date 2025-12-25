// 测试链接 : https://leetcode.cn/problems/number-of-good-paths/
// 对于这题 可以思考的点就是打标签的一种扩展用途
// 对于集合可以是打上另类的标签
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int f[N], mfcnt[N];
vector<int> val;
int Max(int a, int b) { return a > b ? a : b; }
bool cmp(const vector<int>& a, const vector<int>& b) {
    return Max(val[a[0]], val[a[1]]) < Max(val[b[0]], val[b[1]]);
}
class Solution {
    static int find(const int& x) { return x == f[x] ? x : f[x] = find(f[x]); }
    static int merge(const int& a, const int& b) {
        int fa = find(a), fb = find(b), res = 0;
        if (val[f[fa]] > val[f[fb]])
            f[fb] = fa;
        else if (val[f[fa]] < val[f[fb]])
            f[fa] = fb;
        else {
            res = mfcnt[fa] * mfcnt[fb];
            f[fb] = fa;
            mfcnt[fa] += mfcnt[fb];
        }
        return res;
    }

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        val = vals;
        int n = vals.size();
        for (int i = 0; i < n; i++)
            f[i] = i, mfcnt[i] = 1;
        sort(edges.begin(), edges.end(), cmp);

        int ans = n;
        for (int i = 0; i < n - 1; i++)
            ans += merge(edges[i][0], edges[i][1]);
        return ans;
    }
};