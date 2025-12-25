// 参加会议的最多员工数（难题）（需要分析）
// 测试链接 : https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

/*
我的直觉是：找到图中最大的环？若是环长度为2，则可以多加入一个节点？

分析过程：
首先我们可以分析出有两种答案：
第一种： 小环（k == 2）
1. 我们需要先去找到一个小环（长度为2的环）
2. 然后我们分别延伸环中两个节点，找到它们各自的最长链
3. 这两个延伸出去的两条边的长度 l1 与 l2， ans = l1 + l2 + 2
4. 若是图中有多个小环，则 ans = max(ans, {S | l1 + l2 + 2});（其中 S 表示所有小环能延伸的集合）

第二种： 大环（k > 2）
1. 我们要明白一个性质，大环不能去延伸
2. 举个例子： a -> b -> c -> a
3. 我们发现 不管取大环中任何一个元素，它的固定必然是两个环中元素，所以无法通过环外元素取延伸

总体解决方法：
1. 通过拓扑排序处理掉环外的元素
2. 在拓扑的同时去统计每个节点的最长延伸链的长度
3. 最后遍历图中剩下的节点，计算出大环的最大值，以及所有小环的延伸值的和
4. 最后比较获取答案即可

错误点：
1. 分析：
首先我们要知道小环延长链最外端的点，其实是可以继续延伸的
因为最外端的节点其中一个节点是合法的，而另外一个是可以自己选的
那么我们就可以通过无限拼接的方式，去加大小环的答案
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n, 0);  // 统计入度
        vector<bool> vis(n, 0); // 判断节点是否已经走过了
        vector<int> dp(n, 0);   // 以当前节点为结尾的最长长度链
        for (int i = 0; i < n; i++) deg[favorite[i]]++;

        queue<int> q;
        for (int i = 0; i < n; i++) if (!deg[i]) 
            q.push(i);
        

        int u, v;
        while (q.size()) {
            u = q.front(); q.pop();
            vis[u] = 1;
            v = favorite[u];
            if (!(--deg[v])) q.push(v);
            dp[v] = max(dp[v], dp[u] + 1);
        }

        int sans = 0, bans = 0, pre, cnt;
        for (int i = 0; i < n; i++) if (!vis[i]) q.push(i);
        while (q.size())
        {
            u = q.front(); q.pop();
            vis[u] = 1;
            v = favorite[u];
            cnt = 1;
            while (!vis[v]) {
                cnt++;
                pre = u;
                u = v;
                vis[u] = 1;
                v = favorite[u];
            }
            
            // 错误点Ⅰ
            if (cnt == 2)
                sans += dp[u] + dp[pre] + 2;
            else
                bans = max(bans, cnt);
        }
        return max(sans, bans);
    }
};