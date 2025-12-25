// 测试链接：https://leetcode.com/problems/largest-rectangle-in-histogram/
// 单调栈 - 柱状图中最大的矩形
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int sta[N], s, t[N][2];
void pop() { s--; }
int size() { return s; }
void push(int x) { sta[++s] = x; }
int top() { return sta[s]; }
void init() {
    memset(t, 0, sizeof(t));
    memset(sta, 0, sizeof(sta));
    s = 0;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            while (size() && sta[top()] >= heights[i])
            {
                int tmp = top(); pop();
                t[tmp][0] = s ? top() : -1;
                t[tmp][1] = i;
            }
            push(i);
        }

        // 清空栈
        while (size())
        {
            int tmp = top(); pop();
            t[tmp][0] = s ? top() : -1;
            t[tmp][1] = -1;
        }

        // 修正
        for (int i = n - 1; i >= 0; i--)
            while (t[i][1] != -1 && heights[t[i][1]] == heights[i])
                t[i][1] = t[t[i][1]][1];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = ((t[i][1] == -1 ? n - 1 : t[i][1] - 1) - (t[i][0] == -1 ? 0 : t[i][0] + 1)) * heights[i];
            ans = ans > tmp ? ans : tmp;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}