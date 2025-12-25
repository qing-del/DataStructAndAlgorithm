// 测试链接 : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int q[N], h, t;
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        bool flag;
        int l = 0, r = min(n, m), ans = 0, num, rt, rw, sw, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            h = t = 0;
            flag = 1;
            for (rt = 0, rw = m - mid, num = pills; rt < mid || rw < m; rw++)
            {
                while (rt < mid && workers[rw] >= tasks[rt]) q[t++] = tasks[rt++];
                // 当前工人无法完成任务就进入吃药流程
                if (h == t || workers[rw] < q[h])
                {
                    // 若是没有药丸则说明这个工人无法任何任务 无法完成 mid 个任务
                    if (!num)
                    {
                        flag = 0;
                        break;
                    }
                    sw = workers[rw] + strength;
                    num--;
                    while (rt < mid && sw >= tasks[rt]) q[t++] = tasks[rt++];

                    // 强化这个工人之后 依旧无法完成任务 即为无法完成 mid 个任务
                    if (h == t || sw < q[t-1])
                    {
                        flag = 0;
                        break;
                    }
                    else
                        t--;
                }
                else
                    h++;
            }

            if (flag)
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        return ans;
    }
};

// 输入：tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
int main()
{
    vector<int> tasks = { 3, 2, 1 };
    vector<int> workers = { 0, 3, 3 };
    int pills = 1, strength = 1;
    cout << Solution().maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}