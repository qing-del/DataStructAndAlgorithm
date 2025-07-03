#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> is_k;
    vector<int> no_k;
    for(int i = 1; i <= n; i++)
    {
        if(i % k == 0)
        {
            is_k.push_back(i); //可以
        } else
        {
            no_k.push_back(i); //不可以
        }
    }
    int sum_1 = 0, sum_2 = 0;
    for(auto elem : is_k) sum_1 += elem; //可以之和
    for(auto elem : no_k) sum_2 += elem; //不可以之和
    double result_1 = (double)sum_1 / is_k.size();
    double result_2 = (double)sum_2 / no_k.size();
    printf("%.1f %.1f", result_1, result_2);
    return 0;
}