#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int corn = 0;
    int add = 1;
    int begin = 1;
    int end = 1;
    for(int i = 1; i <= k; i++)
    {
        corn += add;
        if(begin == end)
        {
            end++;
            add++;
            begin = 1;
            continue;
        }
        begin++;
    }
    cout << corn << endl;
    return 0;
}