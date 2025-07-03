#include <iostram>
using namespace std;

class Person
{
public:
    void showPerson() const //常函数
    {
        // this->a = 100;  这行会报错
        this->b = 10; //有 mutable 修饰 可以在常函数中被修改；
    }

    int a;
    mutable int b;
}

void Test71()
{
    const Person p1;
    p1.b = 100; //常对象修改变量
}

int main()
{
    Test71();

    return 0;
}