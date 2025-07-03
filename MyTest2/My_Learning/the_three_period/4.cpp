#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    Phone(string pNmae):m_pName(pNmae)
    {

    }

    string m_pName;
};

class Person
{
public:
    Person(string name, string pName):m_name(name), m_Phone(pName)
    {

    }

    string m_name;
    Phone m_Phone;
};

void Test41()
{
    Person p1("Mr.three", "Apple 16 Pro Max");
    cout << p1.m_name << ":" << p1.m_Phone.m_pName << endl;

}

int main()
{
    Test41();

    system("pause");

    return 0;
}