#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int count = 1;

    //正方形
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
        {
            if(count < 10) cout << "0";
            cout << count++;
        }
        cout << endl;
    }

    cout << endl;
    count = 1;

    //三角形
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
        {
            if(a - j <= i + 1) 
            {
                if(count < 10) cout << "0";
                cout << count++;
            } else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}