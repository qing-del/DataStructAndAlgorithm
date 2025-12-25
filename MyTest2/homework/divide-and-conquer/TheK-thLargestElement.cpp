#include <iostream>
using namespace std;
#define endl '\n'
const int N = 1e6 + 10;
int a[N], n, k;

void swap(int& a, int& b)
{
    int t = a; a = b; b = t;
}

int findKthLargest(int l, int r)
{
    if (l >= r) return a[l];
    int mid = l + ((r - l) >> 1);
    int lt = l, rt = r, p = a[mid], i = l;
    while (i <= rt)
    {
        if (a[i] < p)
            swap(a[i++], a[lt++]);
        else if (a[i] > p)
            swap(a[i], a[rt--]);
        else i++;
    }
    return lt >= k - 1 ? findKthLargest(l, lt) : findKthLargest(rt + 1, r);
}


int main()
{
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;
    cout << "entry array:";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << findKthLargest(0, n - 1) << endl;
    return 0;
}