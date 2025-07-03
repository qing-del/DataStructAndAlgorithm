#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;

    if (input > 0)
    {
        cout << "it is +" << endl;
    } else if (input < 0)
    {
        cout << "it is -" << endl;
    } else {
        cout << "it is zero" << endl;
    }
    
    return 0;
}