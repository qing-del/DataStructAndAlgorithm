#include <iostream>
using namespace std;

//欧几里得算法（辗转相除法） （循环写法）
int gcd_01(int da, int xiao)
{
    int temp;
    while(da % xiao != 0)
    {
        temp = da % xiao;
        da = xiao;
        xiao = temp;
    }
    return xiao;
}

//欧几里得算法（辗转相除法） （递归写法）
int gcd_02(int da, int xiao)
{
    if (da % xiao == 0)
    {
        return xiao;
    } else
    {
        return gcd_02(xiao, da % xiao);
    }
    
}

int main()
{
    cout << gcd_01(140, 119) << endl;

    cout << gcd_02(140, 119) << endl;
    
    return 0;
}