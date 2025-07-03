#include <iostream>
using namespace std;

int main()
{
    int year, month;
    cin >> year >> month;
    int Feburary = 28;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        Feburary = 29;
    }
    if(month == 2)
    {
        cout << Feburary << endl;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        cout << 30 << endl;
    } else 
    {
        cout << 31 << endl;
    }
    return 0;
}