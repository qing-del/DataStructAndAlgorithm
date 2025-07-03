#include <iostream>
#include <map>
#include <string>
using namespace std;

void Test01()
{
    string s;
    cin >> s;
    map<char, int> m;

    int size = s.size();
    for (int i = 0; i < size - 4; i++)
    {
        if ((s.at(i) == 'a' || s.at(i) == 'b' || s.at(i) == 'c') && s.at(i + 4) == ';')
        {
            string s1 = s.substr(i, 1);
            string s2 = s.substr(i + 3, 1);
            if (isdigit(s2.at(0)))
            {
                m[s1.at(0)] = (int)(s2.at(0) - '0');
            }
            else if (!m[s2.at(0)])
            {
                m[s1.at(0)] = 0;
            }
            else
            {
                m[s1.at(0)] = m[s2.at(0)];
            }
        }
    }

    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        cout << (*it).second << " ";
    cout << endl;
}

int main()
{
    Test01();
    system("pause");
    return 0;
}