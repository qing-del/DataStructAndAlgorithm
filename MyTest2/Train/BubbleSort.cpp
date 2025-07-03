#include <iostream>
using namespace std;

void BubbleSort(int* arr , int len);
void Swaq(int& a ,int& b);
void PrintArray(int* arr , int len);

//数字交换
void Swaq(int& a , int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//冒泡排序
void BubbleSort(int* arr , int len){
    for(int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swaq(arr[j] , arr[j + 1]);
            }                       
        }
        
    }

}

//打印一维数组
void PrintArray(int* arr , int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main()
{
    int arr[9] = {5,4,3,7,8,9,12,3,55};
    int len = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr , len);
    PrintArray(arr , len);
}