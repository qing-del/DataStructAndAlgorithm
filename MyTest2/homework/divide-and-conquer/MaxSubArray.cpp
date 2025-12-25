#include <iostream>
using namespace std;
#define endl '\n'
const int N = 1e5 + 10;
int a[N], n;

int Max(int a, int b) {return a > b ? a : b;}

int findMaxSum(int l, int r)
{
    if (l == r) return a[l];
    int mid = l + r >> 1;
    int lmax = findMaxSum(l, mid), rmax = findMaxSum(mid + 1, r);
    int lsum = a[mid], rsum = a[mid + 1], sum = 0;
    for (int i = mid; i >= l; i--)
    {
        sum += a[i];
        lsum = Max(lsum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= r; i++)
    {
        sum += a[i];
        rsum = Max(rsum, sum);
    }

    return Max(Max(lmax, rmax), lsum + rsum);
}


int main()
{
    cout<<"n = "; cin>>n;
    cout<<"entry array: ";
    for (int i = 1; i <= n; i++) cin>>a[i];
    cout << findMaxSum(1, n) << endl;
    return 0;
}