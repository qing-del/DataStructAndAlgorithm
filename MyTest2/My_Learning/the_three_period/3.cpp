#include <iostream>
#include <string>
using namespace std;

class Person
{

public:
    Person(int age,string name): m_age(age), m_name(name)
    {

    }
    
    string getName();
    int getAge();
    
private:
    int m_age;
    string m_name;
};

string Person::getName()
    {
        return m_name;
    }

int Person::getAge()
    {
        return m_age;
    }

void Test31()
{
    Person p1(18, "张三");
    cout << p1.getName() << ":" << p1.getAge() << endl;
}

int main()
{
    Test31();

    system("pause");

    return 0;
}