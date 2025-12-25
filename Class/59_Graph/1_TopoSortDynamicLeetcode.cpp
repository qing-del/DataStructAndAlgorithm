// 测试链接 : https://leetcode.cn/problems/course-schedule-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x, n) memset(x, n, sizeof(x))
    const static int N = 2000 + 2;
    const static int M = 2000 * 2000;
    int eh[N], dn, indegree[N];
    struct edge { // 链式前向星
        int to, next;
    } e[M];

    void addE(int u, int v) {
        e[++dn].to = v;
        e[dn].next = eh[u];
        eh[u] = dn;
    }

    void Init() {
        ms(eh, 0);
        ms(indegree, 0);
        dn = 0;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;         // 初始化为空数组
        ans.reserve(numCourses); // 提前分配好内存空间
        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses;i++)
                ans.push_back(i);
            return ans;
        }

        Init();
        for (auto it : prerequisites) {
            addE(it[1], it[0]); // 反向建图 入度越多 该课程的“前置”就越多
            indegree[it[0]]++;
        }

        queue<int> q;
        for (int i = numCourses - 1; i >= 0; i--)
            if (!indegree[i])
                q.push(i);

        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int i = eh[u]; i; i = e[i].next) {
                int v = e[i].to;
                indegree[v]--;
                if (!indegree[v])
                    q.push(v);
            }
        }

        if (ans.size() < numCourses)
            return {};
        return ans;
    }
};