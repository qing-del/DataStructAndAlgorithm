// 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/
// 可以学习一下多源BFS的方法
// 不设置距离数组是因为如果这个点距离这个源头不是最近的话，必然vis已经被标记过了
#include <bits/stdc++.h>
using namespace std;

struct node {
    int i, j, dis;
    node(int i = 0, int j = 0, int dis = 0) : i(i), j(j), dis(dis) {}
};
bool vis[101][101];
int xi[] = { 0,0,1,-1 }, yi[] = { 1,-1,0,0 };
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        int n = grid.size(), m = grid[0].size();
        queue<node> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]) 
                {
                    q.push(node(i, j, 0));
                    vis[i][j] = 1;
                }

        node cur;
        int vi, vj;
        int ans = -1;
        while (q.size())
        {
            cur = q.front(); q.pop();
            for (int k = 0; k < 4; k++)
            {
                vi = cur.i + xi[k], vj = cur.j + yi[k];
                if (vi < 0 || vi >= n || vj < 0 || vj >= m || vis[vi][vj]) continue;
                q.push(node(vi, vj, cur.dis + 1));
                vis[vi][vj] = 1;
                ans = max(ans, cur.dis + 1);
            }
        }
        return ans;
    }
};

/*
输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
*/
int main() {
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    Solution s;
    int ans = s.maxDistance(grid);
    return 0;
}


/*
超时做法：
struct node {
    int i, j, step;
    node(int i=0,int j=0,int step=0) : i(i),j(j),step(step) {}
};
int xi[] = { 1, -1, 0,0 }, yi[] = { 0,0,1,-1 };
int n, m;
bool vis[101][101];
vector<vector<int>> g;
class Solution {
    static int bfs(int i, int j) {
        memset(vis, 0, sizeof(vis));
        queue<node> q;
        q.push(node(i, j, 0));
        vis[i][j] = 1;
        node cur;
        int vi, vj;
        while (q.size()) {
            cur = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                vi = cur.i + xi[k], vj = cur.j + yi[k];
                if (vi < 0 || vi >= n || vj < 0 || vj >= m || vis[vi][vj]) continue;
                if (g[vi][vj] == 1) return cur.step + 1;
                q.push(node(vi, vj, cur.step + 1));
                vis[vi][vj] = 1;
            }
        }
        return -1;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        g = grid;
        int ans = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!g[i][j]) ans = max(ans, bfs(i, j));
        return ans;
    }
};
*/