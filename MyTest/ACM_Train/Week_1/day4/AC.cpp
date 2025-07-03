#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int max = -1, min = 11;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        sum += input;
        max = max > input ? max : input;
        min = min < input ? min : input;
    }
    sum = sum - max - min;
    double result = (double)sum / (n - 2);
    printf("%.2f\n", result);
    return 0;
}