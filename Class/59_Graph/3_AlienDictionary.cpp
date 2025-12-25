// 测试链接: https://leetcode.cn/problems/Jf1JuT/
// 第七次才 AC
#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int dg[N], g[N], vis;    // 使用位运算
class Solution {
    static int lowbit(int x) { return x & -x; }

    static int getBitOneNum(int x) {
        int res = 0;
        while (x)
        {
            x -= lowbit(x);
            res++;
        }
        return res;
    }

    // 获取二进制最右边的 1 处于第几位
    static int getLowbitPos(int x) {
        int tmp = lowbit(x);
        int l = 0, r = 32, mid;
        while (r >= l)
        {
            mid = (l + r) >> 1;
            if (tmp >> mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        if (n == 1) return words[0];
        int pre, cur;
        memset(dg, 0, sizeof(dg));
        memset(g, 0, sizeof(g));
        vis = 0;
        pre = words[0].size();
        for (int i = 0; i < pre; i++) vis |= 1 << (words[0][i] - 'a');
        for (int i = 1, len, j, u, v, flag; i < n; i++)
        {
            cur = words[i].size();
            len = cur, flag = 0;
            if (pre < cur)
            {
                len = pre;
                flag = 1;
            }
            for (j = 0; j < cur; j++) vis |= 1 << (words[i][j] - 'a');
            for(j = 0; j < len; j++)
                if (words[i - 1][j] != words[i][j])
                {
                    u = words[i - 1][j] - 'a';  
                    v = words[i][j] - 'a';
                    if (!((g[u] >> v) & 1)) dg[v]++;
                    g[u] |= 1 << v;
                    flag = 0;
                    break;
                }
            
            // 特判终止条件
            if(j < pre && j == cur) return "";

            if(flag)
            {   
                int u = words[i][cur - 1] - 'a';
                for (j = 0, v; j < pre; j++)
                {
                    v = words[i - 1][j] - 'a';
                    if (!((g[u] >> v) & 1)) dg[v]++;
                    g[u] |= 1 << v;
                }
            }
            pre = cur;
        }
            
        queue<int> q;
        int candidate, allnum = getBitOneNum(vis);
        while (vis)
        {
            candidate = getLowbitPos(vis) - 1;
            vis -= lowbit(vis);
            if (!dg[candidate]) q.push(candidate);
        }

        string ans = "";
        if (allnum!=1 && q.size() == allnum) return ans;
        int u, v;
        while (q.size())
        {
            u = q.front(); q.pop();
            while(g[u])
            {
                candidate = getLowbitPos(g[u]) - 1;
                g[u] -= lowbit(g[u]);
                if (!--dg[candidate]) q.push(candidate);
            }
            ans.push_back(u + 'a');
        }
        return ans.size() == allnum ? ans : "";
    }
};

// 输入：words = ["wrt","wrf","er","ett","rftt"]
int main() {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    Solution s;
    cout << s.alienOrder(words) << endl;
    return 0;
}