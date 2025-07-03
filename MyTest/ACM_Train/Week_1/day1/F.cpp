#include <iostream>
using namespace std;

int main()
{
    int s, v;
    bool pre_day = true;
    cin >> s >> v;
    int HH = 8, MM = 0;
    int time = s / v + 10;
    if(s % v != 0) time++;
    MM -= time;
    while(MM < 0)
    {
        if(HH < 0 && pre_day)
        {
            HH += 24;
            pre_day = false;
        }
        HH--;
        MM += 60;
    }
    if(MM < 0) 
    {
        cout << "00:00" << endl;
        return 0;
    }
    if(MM < 10 && HH < 10)
    {
        cout << "0" << HH << ":0" << MM << endl;
    }else if(HH < 10)
    {
        cout << "0" << HH << ":" << MM << endl;
    }else if(MM < 10)
    {
        cout <<  HH << ":" << "0" << MM << endl;
    } else
    {
        cout <<  HH << ":" << MM << endl;
    }
    return 0;
}