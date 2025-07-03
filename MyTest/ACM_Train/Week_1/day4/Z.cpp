#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int result = 0;
    if(N < 0) 
    {
        cout << "-";
        N = -N;
    }
    while(N > 0)
    {
        if(result != 0) result *= 10;
        result += N % 10;
        N /= 10;
    }
    cout << result << endl;
    return 0;
}