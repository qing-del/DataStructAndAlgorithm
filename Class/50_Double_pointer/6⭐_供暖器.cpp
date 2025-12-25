// 测试链接：https://leetcode.cn/problems/heaters/
// 双指针 --- 供暖器
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static int Abs(int a,int b) { return a > b ? a - b : b - a; }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 0, ans = 0;
        while(l < n)
        {
            while(r < m - 1 && Abs(houses[l], heaters[r]) >= Abs(houses[l], heaters[r + 1])) r++;
            ans = ans > Abs(houses[l], heaters[r]) ? ans : Abs(houses[l], heaters[r]);
            l++;
        }
        return ans;
    }
};

// 输入: houses = [1,2,3], heaters = [2]
int main() {
    vector<int> houses = {1,2,3};
    vector<int> heaters = {2};
    Solution s;
    cout << s.findRadius(houses, heaters) << endl;
    return 0;
}