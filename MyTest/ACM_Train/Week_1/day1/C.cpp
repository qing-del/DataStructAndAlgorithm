#include <iostream>
#include <string>
using namespace std;

void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

int main()
{
    string input;
    cin >> input;
    int size = input.size();
    for(int i = 0; i < size / 2; i++)
    {
        swap(input[i], input[size - 1 - i]);
    }
    cout << input << endl;

    return 0;
}