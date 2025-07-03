#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isNumber(const string &s)
{
    return all_of(s.begin(), s.end(), ::isdigit);
}

int main()
{
    string s1, s2;
    getline(cin, s1, ' ');
    getline(cin, s2);
    if (s2.at(0) == ' ')
        s2.erase(0, 1);

    int A = -1, B = -1, sum = -1;
    if (isNumber(s1) && !(s1.empty()))
        A = stoi(s1);
    if (isNumber(s2))
        B = stoi(s2);

    sum = A + B;
    cout << (A == -1 ? "?" : to_string(A)) << " + "
         << (B == -1 ? "?" : to_string(B)) << " = "
         << ((A == -1 || B == -1) ? "?" : to_string(sum)) << endl;

    system("pause");
    return 0;
}
