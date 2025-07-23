//测试链接：https://leetcode.cn/problems/gas-station/
// 滑动窗口 -- 加油站
#include <bits/stdc++.h>
using namespace std;

// AC 4ms 109.81MB
/* 思想：
首先题目是给了两个数组的 
油 - 距 = 余
那么 如果 余 这个数组中所有的数值累加和大于等于0
那么就可以环绕一圈
对于：理解 l = r + 1 这个点
可以是看作 余 数组中 出现 sum < 0 的情况时
可以说明是这个点以及这个点左边的点 不管从哪个点出发
一直相加过来的 sum 都会是小于0 （这里有点类似于是贪心的思想）
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int l = 0, r = 0, sum = 0; l < n; l = r + 1, r = l) {
            sum = 0;
            while(sum + gas[r % n] - cost[r % n] >= 0) {
                if(r - l + 1 >= n) return l;
                sum += gas[r % n] - cost[r % n];
                r++;
            }
        }
        return -1;
    }
};

/* 示例题解：（0ms）
使用贪心的思想
1.若是能够转一圈 说明其实sum肯定会大于等于0
2.tmp的意义是用于重置起点的 当tmp小于0时，说明在 i+1 之前的起点都是不可以的
*/
class Show_Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,sum=0,tmp=0;
        for(int i=0;i<gas.size();++i){
            sum+=gas[i]-cost[i];
            tmp+=gas[i]-cost[i];
            if(tmp<0){
                start=i+1;
                tmp=0;
            }
        }
 
        return (sum>=0)?start:-1;
    }
};

/*
我的思路：（AC 4ms 109.84MB）
首先是使用 滑动窗口 来实现
1.首先需要前往下一个加油站的前提：拥有足够的油走到下一站
2.若是遇到无法推进右边界的情况下则尝试收缩左边界（更换起点）
3.若是起点和当前位置重叠（还是无法推进右边界） 则进行起点和右边界一起更新
4.若是 左边界 第二次出现在 0 号加油站 说明无法环绕一圈
*/
class My_Solution {
    int n;
    int getR(int r) {
        return r % n;
    }

public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        n = gas.size();
        int l = 0, r = 0;
        int sum = gas[l];
        while (l < n) 
        {
            if (sum >= cost[getR(r)])
            {
                //说明可以向下一个地点出发
                sum -= cost[getR(r)];
                sum += gas[getR(++r)];
            }
            else if (l == r)
            {
                //进入这里说明同一个位置且无法前进
                l++, r++;
                if (l >= n) return -1;
                sum = gas[l];
            }
            else 
            {
                sum -= gas[l];
                sum += cost[l++];
                while (sum < 0 && l < r)
                {
                    sum -= gas[l];
                    sum += cost[l++];
                }
            }

            if (l != r && l == getR(r)) return l;
        }
        return -1;
    }
};

//输入：gas =[4] cost =[5]
int main() {
    vector<int> gas = {4};
    vector<int> cost = {5};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}