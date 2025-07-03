#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string input;
    cin >> input;
    long sum = 0;
    sum = (input.at(0) - '0') + (input.at(2) - '0') * 2 + (input.at(3) - '0') * 3 + (input.at(4) - '0') * 4 + (input.at(6) - '0') * 5 + (input.at(7) - '0') * 6 + (input.at(8) - '0') * 7 + (input.at(9) - '0') * 8 + (input.at(10) - '0') * 9;
    int mod = sum % 11;
    if(input.at(12) == 'X')
    {
        if(mod == 10) 
        {
            cout << "Right" << endl;
            return 0;
        } else
        {
            input[12] = (char)('0' + mod); 
        }
    } else
    {
        if((input.at(12)) - '0' == mod)
        {
            cout << "Right" << endl;
            return 0;
        } else
        {
            if(mod == 10) 
            {
                input[12] = 'X';
            }else
            {
                input[12] = (char)('0' + mod); 
            }
        }
    }
    cout << input << endl;
    return 0;
}