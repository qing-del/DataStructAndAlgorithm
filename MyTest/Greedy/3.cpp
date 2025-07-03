#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int FindMan(vector<int> arr, const int& n, const int& s)
{
    sort(arr.begin(), arr.end());
    return arr[n - s - 1];
}

int main(void)
{
    string number;
    int n, s;
    cin >> number >> s;
    n = 0;
    vector<int> arr;
    for (auto ch : number )
    {   
        arr.push_back(ch - '0');
        n++;
    }
    
    int max = FindMan(arr, n, s);
    for (auto elem : arr)
    {
        if (elem <= max)
        {
            cout << elem;
        }
    }
}