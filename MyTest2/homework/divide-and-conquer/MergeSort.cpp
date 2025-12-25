#include <iostream>
using namespace std;
#define endl '\n'
const int N = 1e5+10;
int a[N], b[N];

void merge(int l, int r)
{
    if(r <= l) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid+1, r);
    int lt = l, rt = mid+1, cur=l;
    while(lt <= mid && rt <= r)
    {
        if(a[lt] <= a[rt]) b[cur++] = a[lt++];
        else b[cur++] = a[rt++];
    }
    while(lt <= mid) b[cur++] = a[lt++];
    while(rt <= r) b[cur++] = a[rt++];
    for(int i = l; i <= r; i++) a[i] = b[i];
}

int main()
{
    int n; cout << "n = "; cin >> n;
    cout << "enter array:";
    for(int i = 1; i <= n; i++) cin>>a[i];
    merge(1, n);
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
