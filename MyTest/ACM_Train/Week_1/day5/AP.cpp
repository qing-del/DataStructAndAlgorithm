#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num[2] = {1, 1};
    string s;
    for (int i = 0; i < 2; i++)
    {
        cin >> s;
        for (int j = 0, size = s.size(); j < size; j++)
        {
            num[i] *= (s[j] - 'A' + 1);
        }
    }
    if (num[0] % 47 == num[1] % 47)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
    return 0;
}