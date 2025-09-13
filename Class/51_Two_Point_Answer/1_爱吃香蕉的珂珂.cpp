// 测试链接：https://leetcode.cn/problems/koko-eating-bananas
// 二分答案 - 爱吃香蕉的珂珂
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = 0;
        long long sum = 0;
        for (int i = 0; i < piles.size(); i++)
            sum += piles[i],
            r = r > piles[i] ? r : piles[i];

        l = sum / h;
        int ans = l;

        while (l <= r)
        {
            int mid = (r + l) >> 1;
            int all = 0;
            for (int i = 0; i < piles.size(); i++)
                all += (piles[i] + (mid - 1)) / mid;
            if (all <= h)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> piles = { 3,6,7,11 };
    cout << s.minEatingSpeed(piles, 8) << endl;
    return 0;
}