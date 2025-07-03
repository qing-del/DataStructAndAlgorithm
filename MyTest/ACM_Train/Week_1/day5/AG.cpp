#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> get_primes(int n)
{
    vector<int> result;
    vector<bool> num(n + 1, true);
    num[0] = false;
    num[1] = false;
    for(int i = 2, N = sqrt(n) + 1; i < N; i++)
    {
        if(num[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                num[j] = false;
            }
        }
    }
    for(int i = 0; i <= n; i++)
    {
        if(num[i]) result.push_back(i);
    }
    return result;
}

int main()
{
    int L;
    cin >> L;
    vector<int> arr = get_primes(L);
    int sum = 0;
    int count = 0;

    for (count = 0; count < arr.size(); count++)
    {
        if (sum + arr[count] <= L)
        {
            sum += arr[count];
            cout << arr[count] << endl;
        }
        else
        {
            break; 
        }
    }
    
    cout << count << endl; 
    return 0;
}