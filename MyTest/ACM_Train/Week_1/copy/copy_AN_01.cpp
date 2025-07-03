#include <iostream>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int boy = 0, girl = 0;
    int len = n.size();
    for (int i = 0; i < len; i++)
    {
        if (n[i] == 'b' && n[i + 1] == 'o' && n[i + 2] == 'y')
        {
            boy++;
            i += 2;
            continue;
        }
        if (n[i] == 'b' && n[i + 1] == 'o')
        {
            boy++;
            i += 1;
            continue;
        }
        if (n[i] == 'o' && n[i + 1] == 'y')
        {
            boy++;
            i += 1;
            continue;
        }
        if (n[i] == 'b')
        {
            boy++;
            continue;
        }
        if (n[i] == 'o')
        {
            boy++;
            continue;
        }
        if (n[i] == 'y')
        {
            boy++;
            continue;
        }
        if (n[i] == 'g' && n[i + 1] == 'i' && n[i + 2] == 'r' && n[i + 3] == 'l')
        {
            girl++;
            i += 3;
            continue;
        }
        if (n[i] == 'g' && n[i + 1] == 'i' && n[i + 2] == 'r')
        {
            girl++;
            i += 2;
            continue;
        }
        if (n[i] == 'i' && n[i + 1] == 'r' && n[i + 2] == 'l')
        {
            girl++;
            i += 2;
            continue;
        }
        if (n[i] == 'g' && n[i + 1] == 'i')
        {
            girl++;
            i += 1;
            continue;
        }
        if (n[i] == 'i' && n[i + 1] == 'r')
        {
            girl++;
            i += 1;
            continue;
        }
        if (n[i] == 'r' && n[i + 1] == 'l')
        {
            girl++;
            i += 1;
            continue;
        }
        if (n[i] == 'g')
        {
            girl++;
            continue;
        }
        if (n[i] == 'i')
        {
            girl++;
            continue;
        }
        if (n[i] == 'r')
        {
            girl++;
            continue;
        }
        if (n[i] == 'l')
        {
            girl++;
            continue;
        }
    }
    cout << boy << endl
         << girl;
    return 0;
}