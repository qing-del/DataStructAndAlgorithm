#include <iostream>
using namespace std;
#define endl '\n'
const int N = 1e5+10;
int a[N];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 三快排
void quickSort(int l, int r) {
    if(l >= r) return;
    int p = a[l];
    int lt=l,rt=r,i=l+1;
    while(i <= rt)
    {
        if(a[i] < p)
            swap(a[i++], a[lt++]);
        else if(a[i] > p)
            swap(a[i], a[rt--]);
        else i++;
    }

    quickSort(l, lt-1);
    quickSort(rt+1, r);
}

int main()
{
    int n; cout << "n = "; cin >> n;
    cout << "enter array:";
    for(int i = 1; i <= n; i++) cin>>a[i];
    quickSort(1, n);
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
