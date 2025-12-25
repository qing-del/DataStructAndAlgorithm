#include <iostream>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10;
int n, a[N], b[N], len;

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    len = 0;
    for (int i = 0; i < n; i++)
        if (b[len] < a[i])
            b[++len] = a[i];
        else
        {
            int l = 1, r = len;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (b[mid] < a[i])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            b[l] = a[i];
        }
    cout << len << endl;
    return 0;
}