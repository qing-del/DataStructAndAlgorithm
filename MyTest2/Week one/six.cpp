#include <iostream>
using namespace std;

int main()
{
    int array[5];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
        sum += array[i];
    }

    cout << static_cast<float>(sum) / 5 << endl;

}