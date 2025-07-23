// 测试连接：https://leetcode.cn/problems/boats-to-save-people/
// 双指针 --- 救生艇
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
    }
};

class My_Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ans = 0;
        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
                l++, r--, ans++;
            else
                r--, ans++;
        }
        return ans;
    }
};

// 输入：people = [3,2,2,1], limit = 3
int main() {
    vector<int> people = {3,2,2,1};
    int limit = 3;
    Solution s;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}