#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct Node 
{
    int l, r;
    Node() {}
    Node(int l, int r) : l(l), r(r) {}
};

const int N = 1e6 + 10;
int arr[N], sta[N], n, s;
Node ans[N];

// sta 数组存放的是 下标
void push(int x) { sta[s++] = x; }
void pop() { s--; }
int top() { return sta[s - 1]; }
int size() { return s; }

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) 
    {
        while (size() && arr[top()] >= arr[i]) 
        {
            int tmp = top(); pop();
            ans[tmp] = Node(size() ? top() : -1, i);
        }
        push(i);
    }

    // 此时栈里面剩余的元素的右边已经没有比它更小的值了
    while (size()) 
    {
        int tmp = top(); pop();
        ans[tmp] = Node(size() ? top() : -1, -1);
    }

    // 修正右侧ans
    for (int i = n - 1; i >= 0; i--) 
        while (ans[i].r != -1 && arr[ans[i].r] == arr[i]) ans[i].r = ans[ans[i].r].r;

    for (int i = 0; i < n; i++) 
        cout << ans[i].l << " " << ans[i].r << endl;
    return 0;
}