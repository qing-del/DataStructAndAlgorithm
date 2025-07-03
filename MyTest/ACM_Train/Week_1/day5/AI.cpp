#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> chimp(34, false);
    vector<int> honor(7, 0);
    int n; //买彩票数量
    cin >> n;
    
    //输入中奖号码
    for(int i = 0; i < 7; i++)
    {
        int input;
        cin >> input;
        chimp[input] = true;
    }

    //输入购买的彩票
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < 7; j++)
        {
            int input;
            cin >> input;
            if(chimp[input]) count++;
        }
        if(count == 0)
        {
            continue;
        } else
        {
            honor[7 - count]++;
        }
    }
    for(auto elem : honor) cout << elem << " ";
    return 0;
}