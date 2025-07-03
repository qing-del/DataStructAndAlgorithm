#include <iostream>
using namespace std;

//个人方法 递归写法
int Multiply_N_Number(int n, int t, int start)
{
    int new_n = (n % 10) * (n % 10); //爆数修改

    if(t == 1)
    {
        if(start % 2 != 0)
        {
            return (n * start) % 10;
        } else 
        {
            return n % 10;
        }
    }
    
    if(new_n == 1)
    {
        if (start % 2 != 0) //个位为一的奇数情况修改
        {
            return start % 10;
        } else
        {
            return 1;
        }
    }

    if (new_n == 0)
    {
        return 0;
    }

    return Multiply_N_Number(new_n, t / 2, n);
}

int gogogo(int n)
{
    int sum = 1;
    int a_n = n % 10;
    for (int i = 0; i < n; i++)
    {
        sum = (sum * a_n) % 10;
    }
    return sum;
}

int main()
{
    int n = 99999999;
    cout << Multiply_N_Number(n, n, n) << endl;
    //cout << gogogo(n) << endl;
    return 0;
}