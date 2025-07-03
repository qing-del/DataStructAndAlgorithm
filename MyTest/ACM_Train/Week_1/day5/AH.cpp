#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    while(n != 1)
    {
        arr.push_back(n);
        if(n % 2 == 0)
        {
            n = n / 2;
        } else
        {
            n = n * 3 + 1;
        }
    }
    arr.push_back(1);
    for(int i = arr.size() - 1; i >= 0; i--) cout << arr[i] << " ";
    return 0;
}