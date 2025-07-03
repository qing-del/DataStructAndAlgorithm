#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DataEntry
{
    int day;
    int time;
};

bool compare(const DataEntry& a, const DataEntry& b)
{
    if (a.time == b.time) return a.day < b.day;
    return a.time > b.time;
}

int main()
{
    vector<DataEntry> arr(7);
    for (int i = 0; i < 7; i++)
    {
        int school, mother;
        cin >> school >> mother;
        arr[i].time = school + mother;
        arr[i].day = i + 1;
    }
    sort(arr.begin(), arr.end(), compare);
    if (arr[0].time <= 8) 
    {
        cout << 0 << endl;
    } 
    else
    {
        cout << arr[0].day << endl;
    }
    return 0;
}
