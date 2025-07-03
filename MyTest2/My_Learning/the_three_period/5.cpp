#include <iostream>
using namespace std;

class Person
{
public:
    static int m_A; //类内声明
}

int Person::m_A = 10; //类外初始化

void Test51()
{
    cout << Person::m_A << endl;
}