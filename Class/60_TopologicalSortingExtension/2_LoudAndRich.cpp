// 喧闹和富有
// 测试链接 : https://leetcode.cn/problems/loud-and-rich/

#include <bits/stdc++.h>
using namespace std;

int n, m, u;
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();
        if (n == 1) return { 0 };
        m = richer.size();
        vector<int> res(n, 0);
        for (int i = 1; i < n; i++) res[i] = i;
        vector<vector<int>> edge(n);
        vector<int> deg(n, 0);
        for (int i = 0; i < m; i++) {
            edge[richer[i][0]].push_back(richer[i][1]);
            deg[richer[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!deg[i]) q.push(i);

        while (q.size()) {
            u = q.front();
            q.pop();

            for (int v : edge[u]) {
                if (!(--deg[v])) q.push(v);
                res[v] = quiet[res[v]] > quiet[res[u]] ? res[u] : res[v];
            }
        }
        return res;
    }
};

/*
输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
*/
int main() {
    vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    Solution().loudAndRich(richer, quiet);
    return 0;
}