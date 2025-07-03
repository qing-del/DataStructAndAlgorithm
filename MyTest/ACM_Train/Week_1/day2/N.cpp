#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int all_pay[3];
    for(int i = 0; i < 3; i++)
    {
        int num, price;
        cin >> num >> price;
        all_pay[i] = 0;
        double need = (double)n / num;
        int prc = need * 1000;
        if(prc % 1000 > 0) need++;
        int need_i = (int)need;
        all_pay[i] = price * need_i;
    }
    int min = all_pay[0];
    for(auto elem : all_pay)
    {
        min = min < elem ? min : elem;
    }
    cout << min << endl;
    return 0;
}