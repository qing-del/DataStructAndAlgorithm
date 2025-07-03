#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    int days, taskNum;
    long long max = 0;
    cin >> n >> days >> taskNum;
    long long reword[days];

    for (int i = 0; i < taskNum; i++)
    {
        int date , request;
        cin >> date >> request;
        reword[i] = 0;

        reword[date - 1] += n - request;
    }

    for (int i = 0; i < days; i++)
    {   
        max = max > reword[i] ? max : reword[i];
    }
    cout << max << endl;
    
}