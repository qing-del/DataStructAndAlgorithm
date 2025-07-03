#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    map<string, int> m;
    for (int i = 0; i < len; i += 5)
    {
        string key1 = s.substr(i, 1);
        string key2 = s.substr(i + 3, 1);
        if (isdigit(s[i + 3]))
            m[key1] = s[i + 3] - '0';
        else if (!m[key2])
            m[key1] = 0;
        else
            m[key1] = m[key2];
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->second << " ";
    }
    return 0;
}