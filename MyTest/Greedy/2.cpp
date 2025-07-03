#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
    int left, right;
};

//依靠左边界 升序排序 ，如果左边界相同就对右边界进行 降序排序
bool compare_01(Interval a, Interval b)
{
    if (a.left == b.left)
    {
        a.right > b.right;
    }
    return a.left < b.left;
}

//依靠右边界 降序排序 ， 若是右边界相同就对左边界进行 升序排序
bool compare_02(Interval a, Interval b)
{
    if (a.right == b.right)
    {
        return a.left < a.left;
    }
    return a.right > b.right;
}

int main()
{
    int L, R;
    cin >> L >> R;

    int n;
    cin >> n;
    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].left >> intervals[i].right;
    }
    
    //第一次排序
    sort(intervals.begin(), intervals.end(), compare_01);

    //初始化边界
    int start, end;

    //计算选定的区间；
    int choose;

    //找出第一个选定的区间
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i].left <= L && intervals[i].right > L)
        {
            start = intervals[i].left;
            end = intervals[i].right;
            choose++;
            break;
        }

        if (i == intervals.size() - 1)
        {
            cout << "No_1" << endl;
            return 0; //终止程序
        }
    }

    //第二次排序
    sort(intervals.begin(), intervals.end(), compare_02);

    //是否能覆盖进行判定；
    if (intervals[0].right < R)
    {
        cout << "No_2" << endl;
    }
    

    int index = intervals.size();
    while(end < R)
    {
        for (int i = 0; i < index; i++)
        {
            if (intervals[i].left <= end)
            {
                index = i;
                end = intervals[i].right;
                choose++;
                continue;
            }

            if (i == index - 1)
            {
                cout << "No_3" << endl;
                return 0;
            }
        }
    }

    cout << choose << endl;
    
    return 0;
}