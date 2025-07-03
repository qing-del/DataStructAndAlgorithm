#include <iostream>
#include <vector>
using namespace std;

void CreatVector_Dont_uss();

int main(void)
{
    
}

void CreatVector_Dont_uss()
{
    vector<int> arr1;           //初始化一个vector数组  
    vector<int> arr2(5);        //初始化一个数量为5的vector数组   
    vector<int> arr3(5,1);      //初始化一个数量为5，初始值为1的vector数组

    vector<vector<int>> mat1(5, vector<int>());           //构建一个有5行，但没有指定列数的二维数组
    vector<vector<int>> mat2(5, vector<int>(6));          //构建一个有5行，且每行6列的二维数组
    vector<vector<int>> mat3(5, vector<int>(5, 1));       //构建一个5行，且每行有6列，初始值为1的二维数组；


    vector<vector<vector<int>>> super_arr(4,vector<vector<int>>(5,vector<int>(6))); //构建一个三维数组，其长度为4，宽度为5，高度为6的三维数组，可以看作一个立方体里面放着数据
    int super_arr_1[4][5][6]; //与上面等价
}

