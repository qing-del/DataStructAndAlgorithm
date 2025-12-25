// 测试链接：https://codeforces.com/problemset/problem/4/A
#include <iostream>
using namespace std;
#define endl '\n'

int main()
{
    int x; cin>>x;
    if(x!=2 && !(x%2))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}