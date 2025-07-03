#include <iostream>
using namespace std;

bool is_run_k(int a)
{
    a = a - 1092;
    if(a % 1092 == 0) return true;
    return false;
}

int main()
{
    int N;
    cin >> N;
    int X = 100, K = 0;
    while(N <= 364 * X || (N - 364 * X) % 1092 != 0 || N - 364 * X == 0)
    {
        X--;
    }
    K = (N - 364 * X) / 1092;
    cout << X << endl;
    cout << K << endl;
    return 0;
}
