// 测试链接 : https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/
// 可以通过双端队列来优化时间复杂度
#include <bits/stdc++.h>
using namespace std;

// 复杂度：n * m
struct node {
    int i, j;
    node(int i = 0, int j = 0) :i(i), j(j) {}
};
int xi[] = { 0,0,1,-1 }, yi[] = { 1,-1,0,0 };
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, n * m));
        deque<node> q;
        q.push_back(node(0, 0));
        dis[0][0] = 0;
        node cur;
        int vi, vj, va, k;
        while (q.size())
        {
            cur = q.front(); q.pop_front();
            for (k = 0; k < 4; k++)
            {
                vi = cur.i + xi[k], vj = cur.j + yi[k];
                if (vi < 0 || vj < 0 || vi >= n || vj >= m) continue;
                va = dis[cur.i][cur.j] + grid[vi][vj];
                if (dis[vi][vj] <= va) continue;
                if (vi == n - 1 && vj == m - 1) return va;
                if (!grid[vi][vj]) q.push_front(node(vi, vj));
                else q.push_back(node(vi, vj));
                dis[vi][vj] = va;
            }
        }
        return 0;
    }
};

/*
输入
grid =
[[0,0,1,1],[1,1,1,1],[0,1,1,1],[1,1,0,1],[1,1,1,1],[1,0,1,0],[1,1,1,1],[1,1,1,1],[1,1,1,0],[0,1,0,0]]
*/

int main() {
    vector<vector<int>> grid = {{0,0,1,1},{1,1,1,1},{0,1,1,1},{1,1,0,1},{1,1,1,1},{1,0,1,0},{1,1,1,1},{1,1,1,1},{1,1,1,0},{0,1,0,0}};
    Solution s;
    int ans = s.minimumObstacles(grid);
}

/*
复杂度：n * m * logn
struct node {
    int i, j, a;
    node(int i = 0, int j = 0, int a = 0) :i(i), j(j), a(a) {}
    bool operator<(const node& x) const { return a > x.a; }
};
int xi[] = { 0,0,1,-1 }, yi[] = { 1,-1,0,0 };
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<node> q;
        q.push(node(0, 0, 0));
        vis[0][0] = 1;
        node cur;
        int vi, vj, k;
        while (q.size())
        {
            cur = q.top(); q.pop();
            for (k = 0; k < 4; k++)
            {
                vi = cur.i + xi[k], vj = cur.j + yi[k];
                if (vi < 0 || vj < 0 || vi >= n || vj >= m || vis[vi][vj])continue;
                if (vi == n - 1 && vj == m - 1) return grid[vi][vj] == 1 ? cur.a + 1 : cur.a;
                q.push(node(vi, vj, grid[vi][vj] == 1 ? cur.a + 1 : cur.a));
                vis[vi][vj] = 1;
            }
        }
        return 0;
    }
};
*/