// 测试链接：https://leetcode.cn/problems/daily-temperatures/
// 单调栈 - 每日温度
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int sta[N], s;
void push(int x) { sta[++s] = x; }
void pop() { s--; }
int top() { return sta[s]; }
int size() { return s; }
void init() { memset(sta, 0, sizeof(sta)); s = 0; }

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        init();
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (size() && temperatures[i] >= temperatures[top()])
            {
                int tmp = top(); pop();
                ans[tmp] = size() ? top() - tmp : 0;
            }
            push(i);
        }

        while (size())
        {
            int tmp = top(); pop();
            ans[tmp] = size() ? top() - tmp : 0;
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        init();
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (size() && temperatures[i] >= temperatures[top()])
            {
                int tmp = top(); pop();
                ans[tmp] = i - tmp;
            }
            push(i);
        }

        // 修正
        for (int i = n - 1; i >= 0; i--)
            while (ans[i] && temperatures[ans[i] + i] == temperatures[i])
                // 防止进入死循环（因为 ans[i + ans[i]] 可能为 0）
                // 例如 temperatures = [80, 80, 70]
                if (!ans[i + ans[i]])
                {
                    ans[i] = 0;
                    break;
                }
                else
                    ans[i] = ans[i + ans[i]] + ans[i];

        return ans;
    }
};

//temperatures = [34,80,80,34,34,80,80,80,80,34]
int main()
{
    vector<int> temperatures = { 34,80,80,34,34,80,80,80,80,34 };
    Solution s;
    vector<int> ans = s.dailyTemperatures(temperatures);
    for(auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}