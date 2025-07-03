#include <iostream>
using namespace std;

int Control(int* arr , int size)
{
    int sum = 0;
    for(int i = 0 ;i < size ; i++){
        sum += *(arr + i);  //运用了指针偏移
    }
    return sum;

}

int main(void)
{
    int arr[3] = {2 , 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << Control(arr , size) << endl;
}