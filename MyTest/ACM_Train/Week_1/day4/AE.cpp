#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, m;
    cin >> l >> m;
    vector<bool> trees(l + 1, true);
    for(int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;
        for(int j = left; j <= right ; j++) trees[j] = false;
    }
    
    int count = 0;
    for(auto elem : trees)
    {
        if(elem) count++;
    }
    cout << count << endl;
    return 0;
}