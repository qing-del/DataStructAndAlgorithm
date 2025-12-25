// 测试链接 : https://leetcode.cn/problems/couples-holding-hands/
// 可以看看这题的思路
#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int f[N], num;
class Solution {
public:
    static int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    static void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa != fb) f[fb] = fa, num--;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int m = n >> 1;
        num = m;
        for (int i = 0; i < m; i++) f[i] = i;
        for (int i = 0; i < n; i += 2) merge(row[i] >> 1, row[i + 1] >> 1);
        return m - num;
    }
};

// 输入: row = [0,2,1,3]
int main()
{
    vector<int> row = { 0,2,1,3 };
    cout << Solution().minSwapsCouples(row) << endl;
    return 0;
}