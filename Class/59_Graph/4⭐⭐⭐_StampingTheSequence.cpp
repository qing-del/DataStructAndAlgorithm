// 测试链接 : https://leetcode.cn/problems/stamping-the-sequence/
/*
这题很有意思，一般第一时间会反应不过来是拓扑排序
首先这题难就难在怎么去想到拓扑排序
我们拿个例子来分析思路：

1. 假设 stamp="abc"， target="aabcbc"

2. 我们可以去遍历 [0, 3] 这个区间内每个位置所拥有的错误点
我们会得到 错误点分别是如下
位置 0 ： 错误点是 1，2 （2 个）
位置 1 ： 没有错误点 （0 个）
位置 2 ： 错误点是 2，3，4 （3 个）
位置 3 ： 错误点是 3，4 （2 个）

3. 再次分析，可以是发现错误点是可以被下一个印章取消的，比如印在 位置1 可以取消掉 1，2，3 这三个位置的错误
进而我们可以得出就是：
Ⅰ：最后一个印章的错误必须是0
Ⅱ：每次把错误点为 0 的拿出来 然后抵消掉其他位置的错误点 若是错误点为 0 那么可以作为是下一个印章的位置

4. 分析到这里，其实已经可以看出来是拓扑的影子了

细节：
这道题建图有点讲究，可以通过 （错误点 -> 开头） 这种做法来进行入度的计算
然后拓扑排序的时候，需要通过开头点取消掉 覆盖位置的错误点
假设 n = stamp.size(), m = target.size()
那么我们进行位置 i 的拓扑排序的时候，需要遍历 [i, i + n - 1] 这个区间内所有的错误点并且将他们取消掉
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, len, pos;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        n = stamp.size(), m = target.size();
        if (n == m) {
            if (stamp == target) return { 0 };
            return {};
        }
        len = m - n + 1;
        vector<int> error(len, n);
        vector<int> ans(len);
        queue<int> q;
        vector<vector<int>> edge(m);

        for (int i = 0; i < len; i++)
            for (int j = 0; j < n; j++)
                if (stamp[j] == target[i + j]) {
                    if (!(--error[i])) q.push(i);
                }
                else edge[i + j].push_back(i);

        if (q.empty()) return {};

        
        vector<bool> vis(m, 0); // 错误点之一：错误点取消不要重复计算

        while (q.size())
        {
            pos = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                if (vis[pos + i]) continue;
                vis[pos + i] = 1;
                for (int v : edge[i + pos])
                    if (!(--error[v])) q.push(v);
            }
            ans[--len] = pos;
        }
        if(len) return {};
        return ans;
    }
};

int main()
{
    // 错误点 1 的 hack 例子
    string stamp = "uskh";
    string target = "uskhkhhskh";
    Solution().movesToStamp(stamp, target);
    return 0;
}