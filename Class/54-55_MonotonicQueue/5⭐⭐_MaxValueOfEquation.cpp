// 测试链接 : https://leetcode.cn/problems/max-value-of-equation/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int dis, x;
    node(int dis = 0, int x = 0) : dis(dis), x(x) {}
};
const int N = 1e5 + 10;
node q[N];
int h, t;
class Solution {
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        h = t = 0;
        q[t++] = node(points[0][1] - points[0][0], points[0][0]);
        int ans = -1e9;
        for (int i = 1, sum; i < n; i++)
        {
            sum = points[i][0] + points[i][1];
            while (t > h && points[i][0] - q[h].x > k) h++;
            if (t > h) ans = Max(ans, sum + q[h].dis);
            sum = points[i][1] - points[i][0];
            while (t > h && q[t - 1].dis <= sum) t--;
            q[t++] = node(sum, points[i][0]);
        }
        return ans;
    }
};