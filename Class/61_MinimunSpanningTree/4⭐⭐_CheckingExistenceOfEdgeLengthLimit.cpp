// 测试链接 : https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/
// 如何查询，似乎会TEL？
// 可以使用离线查询，对边和问题进行排序
// 每进行一次查询之前，就将小于该次查询的边都使用最小生成树合并一下
// 剩下未处理的就是无法满足的查询

// ⭐错误思路：先合并再查询是错误的
#include <bits/stdc++.h>
using namespace std;

struct query {
    int u, v, w, i;
    query(int u=0, int v=0, int w=0, int i=0) : u(u), v(v), w(w), i(i) {}
    bool operator<(const query& x) const { return w < x.w; }
};

class Solution {
    int find(vector<int>& f, int x) {
        return x == f[x] ? x : f[x] = find(f, f[x]);
    }

    void merge(vector<int>& f, int a, int b) {
        int fa = find(f, a), fb = find(f, b);
        if (fa != fb) f[fb] = fa;
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        int m = queries.size(), len = edgeList.size(), cnt = 0, i, j;
        vector<query> question(m);
        for (int i = 0; i < m; i++)
            question[i].u = queries[i][0], question[i].v = queries[i][1], question[i].w = queries[i][2], question[i].i = i;
        sort(question.begin(), question.end());
        vector<bool> ans(m, true);
        vector<int> f(n);
        for (i = 0; i < n; i++) f[i] = i;
        for (i = 0, j = 0; i < m; i++) {
            while(j < len && edgeList[j][2] < question[i].w) {
                if (find(f, edgeList[j][0]) != find(f, edgeList[j][1])) {
                    merge(f, edgeList[j][0], edgeList[j][1]);
                    cnt++;
                }
                j++;
            }
            if (find(f, question[i].u) != find(f, question[i].v)) ans[question[i].i] = 0;
            if (j == len || cnt == n - 1) break;
        }
        while (i < m) {
            if (find(f, question[i].u) != find(f, question[i].v)) ans[question[i].i] = 0;
            i++;
        }
        return ans;
    }
};
/*
输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
*/
int main() {
    int n = 3;
    vector<vector<int>> edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    vector<vector<int>> queries = {{0,1,2},{0,2,5}};
    Solution s;
    vector<bool> ans = s.distanceLimitedPathsExist(n, edgeList, queries);
    return 0;
}
