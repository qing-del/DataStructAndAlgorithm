// 测试链接 : https://leetcode.cn/problems/similar-string-groups/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 10;
int f[N], ans;
class Solution {
    static bool isSimilar(string& a, string& b) {
        int cnt = 0, asize = a.size(), bsize = b.size();
        if (asize != bsize) return false;
        for (int i = 0; i < asize; i++)
            if (a[i] != b[i] && ++cnt > 2) return false;
        return true;
    }
    static int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    static void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) f[fb] = fa, ans--;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        ans = n;
        for (int i = 0; i < n; i++) f[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (find(i) != find(j) && isSimilar(strs[i], strs[j]))
                    merge(i, j);
        return ans;
    }
};