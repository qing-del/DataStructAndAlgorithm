#include <iostream>
#include <string>
using namespace std;

int main()
{
    int L;
    string s;
    cin >> L >> s;
    int size = s.size();
    for(int i = 1; i < size; i+=2)
    {
        int mid = i / 2;
        string s1 = s.substr(0,mid + 1);
        string s2 = s.substr(mid + 1, mid + 1);
        if(s1 == s2) 
        {
            cout << mid + 1 << endl;
            break;
        }
    }
    system("pause");
    return 0;
}