#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s[n * 2];

    int time = 0;
    int max,temp,maxnum,minnum;

    for(int i = 0;i < n * 2 ;i++)
    {
        cin >> s[i];
    }

    for(int i = 0; i < n * 2;i += 2)
    {
        if(time == 0)
        {
            maxnum = s[i + 1];
            minnum = s[i];
            temp = maxnum - minnum;
            max = temp;
            time = 1;
        } else {
            if(s[i] <= maxnum && s[i + 1] >= minnum)
            {
                maxnum = maxnum > s[i + 1] ? maxnum : s[i + 1];
                minnum = minnum < s[i] ? minnum : s[i];
                temp = maxnum - minnum;
                max = max > temp ? max : temp;
            } 
            else {
                maxnum = s[i + 1];
                minnum = s[i];
                temp = maxnum - minnum;
                max = max > temp ? max : temp;
            }
        }
    }

    cout << max << endl;

    return 0;
}