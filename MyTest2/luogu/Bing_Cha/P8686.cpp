#include <iostream>
#include <vector>
using namespace std;

int findx(int x, vector<int> &arr)
{
    if(x == arr[x]) return x;
    arr[x] = findx(arr[x], arr);
    return arr[x];
}

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N + 20);
    for(int i = 0; i < N + 20; i++)
        arr[i] = i;
    for(int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        a = findx(a, arr);
        arr[a] = findx(a, arr) + 1;
        cout << a << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}