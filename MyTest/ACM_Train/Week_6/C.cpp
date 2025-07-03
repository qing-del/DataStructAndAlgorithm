#include <iostream>
using namespace std;
#include <string>
const int N = 30 + 5;
int a[N][N], n;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j >= n || j < 0)
        return;
    if (a[i][j] == 0)
    {
        a[i][j] = 2;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }
    else
        return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int first_one_i, first_one_j, a_zero_i, a_zero_j;
    for(int i = 0; i<n;i++)
        for(int j = 0;j<n;j++)
            if (a[i][j] == 1)
            {
                first_one_i = i;
                first_one_j = j;
                goto out;
            }
    out:
    a_zero_i = first_one_i + 1; a_zero_j = first_one_j;
    while (a[a_zero_i][a_zero_j] != 0)
    {
        if (first_one_j + 1 < n)
        {
            first_one_j++;
            a_zero_j = first_one_j;
        }
        else
        {
            first_one_i++;
            first_one_j = 0;
            a_zero_i = first_one_i + 1;
            a_zero_j = first_one_j;
        }
    }
    dfs(a_zero_i, a_zero_j);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}