#include <iostream>
using namespace std;

void swap_usingPointor(int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

int main(void)
{
    int a = 3, b = 5;

    cout << a << b << endl;

    swap_usingPointor(&a , &b);

    cout << a << b << endl;

}