#include <iostream>
using namespace std;
#include <string>

int get_int(string s, int i)
{
    string num_s;
    num_s = string(1, s.at(i));
    return stoi(num_s);
}

int main()
{
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    int size = s.size();
    for (int i = 0; i < size - 4; i++)
    {
        if(isdigit(s.at(i+4) != ';')) continue;

        if (s.substr(i, 3) == "a:=")
        {
            if (isdigit(s.at(i + 3)))
            {
                a = get_int(s, i + 3);
                i += 3;
            }
            else
            {
                if (s.at(i + 3) == 'b')
                    a = b;
                if (s.at(i + 3) == 'c')
                    a = c;
            }
        }
        else if (s.substr(i, 3) == "b:=")
        {
            if (isdigit(s.at(i + 3)))
            {
                b = get_int(s, i + 3);
                i += 3;
            }
            else
            {
                if (s.at(i + 3) == 'a')
                    b = a;
                if (s.at(i + 3) == 'c')
                    b = c;
            }
        }
        else if (s.substr(i, 3) == "c:=")
        {
            if (isdigit(s.at(i + 3)))
            {
                c = get_int(s, i + 3);
                i += 3;
            }
            else
            {
                if (s.at(i + 3) == 'a')
                    c = b;
                if (s.at(i + 3) == 'b')
                    c = a;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    system("pause");
    return 0;
}