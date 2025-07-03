#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double p = 0.5 * (a + b + c);
    double square = sqrt(p * (p - a) * (p - b) * (p - c));
    square = round(square * 10) / 10;
    printf("%.1f\n", square);
    return 0;
}
