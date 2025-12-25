// 链接测试 : https://leetcode.cn/problems/find-all-people-with-secret/
#include <bits/stdc++.h>
using namespace std;

// 这里不使用引用传递会导致时间很慢（常数很大，并不是复杂度高）
bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}
const int N = 2e5 + 10;
int f[N];
class Solution {
    static int Max(int a, int b) { return a > b ? a : b; }
    static int Min(int a, int b) { return a < b ? a : b; }
    static int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    static void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) f[Max(fa, fb)] = Min(fa, fb);
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int len = meetings.size();
        for (int i = 0; i < n; i++) f[i] = i;
        f[firstPerson] = 0;
        sort(meetings.begin(), meetings.end(), cmp);

        // 这里使用双指针去维护一个区间
        // 可以将时间复杂度优化到 O(n)
        int l = 0, r = 0, ct, i;
        while (r < len)
        {
            ct = meetings[r][2];
            while (r < len - 1 && ct == meetings[r + 1][2]) r++;
            for (i = l; i <= r; i++)
                merge(meetings[i][0], meetings[i][1]);

            // 这里的撤销有说法
            // 若是直接引用 f[i]!=0 的话有可能会有 f[1]=0,f[2]=1 这样会出错
            // 所以需要去找它的代表节点
            for (i = l; i <= r; i++)
            {
                if (find(meetings[i][0])) f[meetings[i][0]] = meetings[i][0];
                if (find(meetings[i][1])) f[meetings[i][1]] = meetings[i][1];
            }

            l = ++r;
        }

        vector<int> ans;
        for (i = 0; i < n; i++)
            if (!find(i)) ans.push_back(i);
        return ans;
    }
};
int main()
{
    vector<vector<int>> meetings = { {1,2,5},{2,3,8},{1,5,10},{5,6,15},{2,4,12} };
    cout << Solution().findAllPeople(6, meetings, 1) << endl;
    return 0;
}