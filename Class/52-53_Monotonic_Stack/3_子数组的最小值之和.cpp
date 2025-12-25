// 测试链接：https://leetcode.cn/problems/sum-of-subarray-minimums/
// 单调栈 - 子数组的最小值之和
#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7, N = 3e4 + 10;
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
    int sumSubarrayMins(vector<int>& arr) {
        init();
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (size() && arr[top()] >= arr[i])
            {
                int tmp = top();
                pop();
                t[tmp][0] = size() ? top() : -1;
                t[tmp][1] = i;
            }
            push(i);
        }

        // 清空栈
        while (size())
        {
            int tmp = top();
            pop();
            t[tmp][0] = size() ? top() : -1;
            t[tmp][1] = -1;
        }

        // 修正右侧答案
        // for (int i = n - 1; i >= 0; i--)
        //     while (t[i][1] != -1 && arr[t[i][1]] == arr[i])
        //         t[i][1] = t[t[i][1]][1];

        // 计算 ans
        for (int i = 0; i < n; i++)
        {
            int head = t[i][0] == -1 ? i + 1 : i - t[i][0],
                tail = t[i][1] == -1 ? n - i : t[i][1] - i;
            ans = ((1LL * arr[i] * head * tail % P) + ans) % P;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3,1,2,4};
    cout << s.sumSubarrayMins(arr) << endl;
    return 0;
}