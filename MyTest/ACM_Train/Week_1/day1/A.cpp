#include <iostream>
using namespace std;

int main()
{
    char c;
    cin >> c;
    int num = 2;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j > num + i) break;
            if(j >= num - i && j <= num + i)
            {
                cout << c;
            } else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}