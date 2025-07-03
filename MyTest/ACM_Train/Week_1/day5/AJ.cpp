#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int num;
    int time;
};

bool compair(Pair a, Pair b)
{
    if(a.time == b.time) return a.num < b.num;
    return a.time > b.time;
}

int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int size = s1 + s2 + s3 + 1;
    vector<Pair> arr(size);
    for(int i = 0; i < size; i++)
    {
        arr[i].num = i;
        arr[i].time = 0;
    } 
    for(int i = 1; i <= s1; i++)
    {
        for(int j = 1; j <= s2; j++)
        {
            for(int k = 1; k <= s3; k++)
            arr[i + j + k].time++;
        }
    }
    sort(arr.begin(), arr.end(), compair);
    cout << arr[0].num << endl;
    return 0;
}