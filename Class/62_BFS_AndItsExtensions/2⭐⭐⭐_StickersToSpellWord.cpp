// 测试链接 : https://leetcode.cn/problems/stickers-to-spell-word/
// 这个题目看到我第一时间也不能说毫无思路，只想到了最暴力的方法
// 本题是 BFS ＋ 剪枝 就是解法

/*
分析：
1） 首先这题说可以将单词剪碎重新排序，那么单词中字符的顺序就不重要了，可以先对所有单词进行排序
2） 然后就可以用 BFS 开始搜索了

剪枝策略：
    可以先使用前缀是否满足
    例如target排序之后是"aaaabbbcccccdd"
    有三张贴纸"aaac", "bbccdk", "aaabbbbbbck"
    那我在完全消掉前面4个a之前，都不会使用第二张贴纸


常数优化：
1. 可以尝试不要拷贝，如果出现不相同，就push_back进去，这样比erase快一点
2. 把迭代器换成下标，这样速度会快一点
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        sort(target.begin(), target.end());
        int n = stickers.size();
        for (int i = 0; i < n; i++) sort(stickers[i].begin(), stickers[i].end());
        map<string, bool> vis;
        queue<int> qs;
        queue<string> q;

        string cur;
        int ans = 1000, st;
        q.push(target);
        qs.push(0);
        vis[target] = 1;
        while (q.size())
        {
            cur = q.front(); q.pop();
            st = qs.front(); qs.pop();
            int p1, p2, len1 = cur.size(), len2;
            for (int i = 0; i < n; i++)
            {
                p2 = 0, len2 = stickers[i].size();
                while (p2 < len2 && stickers[i][p2] != cur[0]) p2++;
                if (p2 == len2) continue;
                string next = "";
                next.reserve(len1);
                for (p1 = 0; p1 < len1 && p2 < len2;)
                {
                    if (cur[p1] == stickers[i][p2])
                        p1++, p2++;
                    else if (cur[p1] < stickers[i][p2])
                    {
                        next.push_back(cur[p1]);
                        p1++;
                    }
                    else
                        p2++;
                }

                while (p1 < len1)
                    next.push_back(cur[p1++]);
                

                if (next.empty())
                {
                    ans = min(ans, st + 1);
                    continue;
                }

                if (!vis.count(next))
                {
                    q.push(next);
                    qs.push(st + 1);
                    vis[next] = 1;
                }
            }
        }
        return ans == 1000 ? -1 : ans;
    }
};

/*
输入： stickers = ["with","example","science"], target = "thehat"
*/
int main() {
    vector<string> stickers = {"with","example","science"};
    string target = "thehat";
    Solution s;
    int ans = s.minStickers(stickers, target);
    return 0;
}