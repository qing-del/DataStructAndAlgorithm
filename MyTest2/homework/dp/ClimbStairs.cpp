#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int cur=2,pre=1;
        for(int i=3;i<=n;i++)
        {
            int next=pre+cur;
            pre=cur;
            cur=next;
        }
        return cur;
    }
};