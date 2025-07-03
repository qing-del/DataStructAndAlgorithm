#include <iostream>
using namespace std;

int main()
{
    double s;  //目标路程
    cin >> s;
    double already = 0; //积累路程
    double Radio = 0.98; //衰减倍数
    int step = 0;  //步数
    double len = 2.0; //开始步长
    while(already - s < 10e-5)
    {
        already += len;
        step++;
        len = len * Radio;
    }
    cout << step << endl;
    return 0;
}