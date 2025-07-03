#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// container : vector
// algorithm : for_each
// iterator : vector<int>::iterator

int main()
{
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向容器第一个元素
    vector<int>::iterator itEnd = v.end(); //结束迭代器 指向容器中最后一个元素的 下一位

    system("pause");
    return 0;
}