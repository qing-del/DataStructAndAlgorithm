#include <bits/stdc++.h>
using namespace std;

class Solution {
    static int Max(int a, int b) { return a > b ? a : b; }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return { nums[0] };
        if (k == 1) return nums;
        vector<int> ans(n - k + 1, 0);
        if (n == k) {
            int maxn = nums[0];
            for (int i = 1; i < n; i++) maxn = Max(maxn, nums[i]);
            for (int i = 0, len = n - k + 1; i < len; i++) ans[i] = maxn;
            return ans;
        }
        deque<int> q;

        for (int i = 0; i < k - 1; i++)
            if (q.size())
            {
                if (nums[i] > nums[q.front()]) q.push_front(i);
                else 
                {
                    while (nums[i] > nums[q.back()]) q.pop_back();
                    q.push_back(i);
                }
            }
            else
                q.push_back(i);
        

        for (int l = 0, r = k - 1; r < n; l++, r++)
        {
            while (q.size() && q.front() < l) q.pop_front();

            if (q.empty() || nums[r] > nums[q.front()]) q.push_front(r);
            else
            {
                while (q.size() && nums[r] > nums[q.back()]) q.pop_back();
                q.push_back(r);
            }
            ans[l] = nums[q.front()];
        }
        return ans;
    }
};