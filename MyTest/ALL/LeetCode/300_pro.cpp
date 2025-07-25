#include <bits/stdc++.h>
using namespace std;

//贪心＋二分答案
class Solution {
    int Max(const int& a, const int& b) {return a>b?a:b;}
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=1, n=nums.size();
        vector<int> d(n+1,0);
        d[len]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>d[len])
                d[++len]=nums[i];
            else
            {
                int l=1,r=len,pos=0;
                while(l<r)
                {
                    int mid=(l+r)>>1;
                    if(d[mid]<nums[i])
                    {
                        pos=mid;
                        l=mid+1;
                    }
                    else
                        r=mid;
                }
                d[pos+1]=nums[i];
            }
        }
        return len;
    }
};