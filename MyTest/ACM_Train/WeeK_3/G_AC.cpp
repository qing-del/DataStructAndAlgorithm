#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  // 使用 NULL 替代 nullptr
    string s;
    int sum = 0;
    map<string, int> a;

    while (getline(cin, s))
    {
        if (s.empty()) break;
        a[s]++;
        sum++;
    }

    for (map<string, int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        cout << it->first << " ";
        cout << fixed << setprecision(4) << (double)((it->second / (double)sum) * 100) << endl;
    }
    return 0;
}
