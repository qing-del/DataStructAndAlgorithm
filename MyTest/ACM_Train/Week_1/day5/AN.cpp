#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int size = input.size();
    int boy = 0, girl = 0;
    for(int i = 0; i < size; i++)
    {
        if(input.at(i) == '.') continue;
        if(input.at(i) == 'b')
        {
            if(i < size - 2 && input.at(i + 1) == 'o' && input.at(i + 2) == 'y')
            {
                boy++;
                i = i + 2;
            } else if(i < size - 2 && input.at(i + 1) == 'o')
            {
                boy++;
                i = i + 1;
            } else if(i < size - 2)
            {
                boy++;
            }
        } else if(input.at(i) == 'o')
        {
            if(i < size - 1 && input.at(i + 1) == 'y')
            {
                boy++;
                i = i + 1;
            } else if (i < size - 1)
            {
                boy++;
            }
        } else if(input.at(i) == 'y')
        {
            boy++;
        } else if(input.at(i) == 'g')
        {
            if(i < size - 3 && input.at(i+1) == 'i' && input.at(i+2) == 'r' && input.at(i+3) == 'l')
            {
                girl++;
                i = i + 3;
            } else if(i < size - 3 && input.at(i+1) == 'i' && input.at(i+2) == 'r')
            {
                girl++;
                i = i + 2;
            } else if(i < size - 3 && input.at(i+1) == 'i')
            {
                girl++;
                i = i + 1;
            } else if(i < size - 3)
            {
                girl++;
            }
        } else if(input.at(i) == 'i')
        {
            if(i < size - 2 && input.at(i+1) == 'i' && input.at(i+2) == 'r')
            {
                girl++;
                i = i + 2;
            } else if (i < size - 2 && input.at(i+1) == 'i')
            {
                girl++;
                i = i + 1;
            } else if (i < size - 2)
            {
                girl++;
            }
        } else if (input.at(i) == 'r')
        {
            if(i < size - 1 && input.at(i+1) == 'l')
            {
                girl++;
                i++;
            } else if (i < size - 1)
            {
                girl++;
            }
        } else if (input.at(i) == 'l')
        {
            girl++;
        }
    }
    cout << boy << endl;
    cout << girl << endl;
    system("pause");
    return 0;
}