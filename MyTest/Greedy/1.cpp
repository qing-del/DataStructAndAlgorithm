#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, end;
};

bool compare(Activity a, Activity b)
{
    return a.end < b.end;
}

int main()
{   
    int n;
    vector<Activity> act(n);
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].start >> act[i].end;
    }
    sort(act.begin(),act.end(),compare);
    
    int count = 1;
    int last_end = act[0].end;

    for (int i = 0; i < n; i++)
    {
        if(act[i].start >= last_end)
        {
            count++;
            last_end = act[i].end;
        }
    }

    cout << last_end << endl;
    

    return 0;
}