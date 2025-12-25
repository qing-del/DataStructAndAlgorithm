// 测试链接：https://codeforces.com/problemset/problem/282/A
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int t; cin >> t;
    int ans = 0;
    while (t--)
    {
        cin >> s;
        if (s.find('+') != string::npos)
            ans++;
        else
            ans--;
    }
    cout << ans << endl;
    return 0;
}