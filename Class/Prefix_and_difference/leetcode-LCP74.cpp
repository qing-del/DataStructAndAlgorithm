//测试连接：https://leetcode.cn/problems/xepqZ5/
//力扣 LCP 74. 最强祝福力场 -- （离散化 + 二位差分 + 二维前缀和）
/* 分析：
第一步：
根据题目的意思，发现给定的
正方形中心坐标是整数 同时边长也是整数
所以可以说明 不管这两个值怎么变化 最小的数 为 0.5
所以可以将坐标进行放大处理（坐标轴放大两倍 都变成整数去处理这个题目）

第二步：
第一步搞完之后 会发现数字特别大
这个时候 要去获取每一个 x y 的值 然后进行排序
利用 map 映射去完成离散化的操作

离散化处理之后 就可以进行二维差分了 */

/* 错误点：
1. 二维差分的处理需要注意边界问题 （在离散化进行位运算的时候，要使用括号进行优先级处理，否则会出现一些错误 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class Solution {
#define ll long long
#define il inline
    il int Max(int a, int b) { return a > b ? a : b; }
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int n = forceField.size();
        map<ll, int> mx, my;   //映射表（用于离散化操作）
        vector<ll> a(n), b(n), r(n);
        //1.先进行放大处理
        for (int i = 0; i < n; i++)
            a[i] = forceField[i][0] << 1,    //代表x
            b[i] = forceField[i][1] << 1,    //代表y
            r[i] = forceField[i][2] << 1;    //代表边长

        //2.离散化操作
        vector<ll> f(2 * n);
        
        //处理 x 坐标相关的离散化
        for (int i = 0, cnt = 0; i < n; i++)
        {
            f[cnt++] = a[i] - (r[i] >> 1);
            f[cnt++] = a[i] + (r[i] >> 1);
        }
        sort(f.begin(), f.end());
        for (int i = 0, len = f.size(), cnt = 0; i < len; i++)
            if (!mx.count(f[i])) mx[f[i]] = ++cnt;

        //处理 y 坐标相关的离散化
        for (int i = 0, cnt = 0; i < n; i++)
        {
            f[cnt++] = b[i] - (r[i] >> 1);
            f[cnt++] = b[i] + (r[i] >> 1);
        }
        sort(f.begin(), f.end());
        for (int i = 0, len = f.size(), cnt = 0; i < len; i++)
            if (!my.count(f[i])) my[f[i]] = ++cnt;

        //3.进行二位差分处理
        int xm = (*(--mx.end())).second, ym = (*(--my.end())).second;
        vector<vector<int>> d(xm + 3, vector<int>(ym + 3, 0));
        for (int i = 0; i < n; i++)
        {
            // 1 表示左上角坐标， 2 表示右下角坐标
            int x1 = mx[a[i] - (r[i] >> 1)] + 1,
                y1 = my[b[i] - (r[i] >> 1)] + 1,
                x2 = mx[a[i] + (r[i] >> 1)] + 1,
                y2 = my[b[i] + (r[i] >> 1)] + 1;

            d[x1][y1]++;
            d[x1][y2 + 1]--;
            d[x2 + 1][y1]--;
            d[x2 + 1][y2 + 1]++;
        }

        //4.将二维差分进行构建获得单点查询的值
        //error-1 PS:该题目需要对边界进行处理，因为边界叠加也算是叠加
        for (int i = 1; i <= xm + 1; i++)
            for (int j = 1; j <= ym + 1; j++)
                d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];

        int ans = 0;
        for (int i = 1; i <= xm + 1; i++)
            for (int j = 1; j <= ym + 1; j++)
                ans = Max(ans, d[i][j]);

        return ans;
    }
};

//示例 AC 代码（常数优化更好）
class Solution_2 {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        set<long long> xs;
        set<long long> ys;
        for (int i = 0; i < forceField.size(); i++) {
            long long x = forceField[i][0];
            long long y = forceField[i][1];
            long long r = forceField[i][2];
            xs.insert((x << 1) - r);
            xs.insert((x << 1) + r);
            ys.insert((y << 1) - r);
            ys.insert((y << 1) + r);
        }

        vector<long long> xx(xs.begin(), xs.end());
        vector<long long> yy(ys.begin(), ys.end());

        int diff[202][202] = { 0 };
        for (int i = 0; i < forceField.size(); i++) {
            long long x = forceField[i][0];
            long long y = forceField[i][1];
            long long r = forceField[i][2];
            int x1 = (lower_bound(xx.begin(), xx.end(), (x << 1) - r) - xx.begin()) + 1;
            int y1 = (lower_bound(yy.begin(), yy.end(), (y << 1) - r) - yy.begin()) + 1;
            int x2 = (lower_bound(xx.begin(), xx.end(), (x << 1) + r) - xx.begin()) + 1;
            int y2 = (lower_bound(yy.begin(), yy.end(), (y << 1) + r) - yy.begin()) + 1;
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }

        int Max = 0;
        for (int i = 1; i <= 2 * forceField.size(); i++) {
            for (int j = 1; j <= 2 * forceField.size(); j++) {
                diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
                Max = max(Max, diff[i][j]);
            }
        }
        return Max;
    }
};

//输入： forceField = [[0,0,1],[1,0,1]]
int main() {
    Solution sol;
    vector<vector<int>> forceField = { {0, 0, 1}, {1, 0, 1} };
    cout << sol.fieldOfGreatestBlessing(forceField) << endl; // 输出：3
    return 0;
}