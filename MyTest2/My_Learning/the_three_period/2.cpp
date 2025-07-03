#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int age;
public:
    Person(int age);
    ~Person();
};

Person::Person(int age)
{
    cout << "构造函数被调用" << endl;
    this->age = age;
}

Person::~Person()
{
    cout << "析构函数被调用" << endl;
}


int main(void)
{
    Person p1(10);

}