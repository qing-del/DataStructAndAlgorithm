#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14;

class Circle
{
public:
    double m_r;

    double calculateZC()
    {
        return 2 * m_r * PI;
    }
};

class Student
{
public:
    string name;
    string number;

    void setName(string name)
    {
        this->name = name;
    }

    void setNumber(string number)
    {
        this->number = number;
    }

    string getName()
    {
        return name;
    }

    string getNumber()
    {
        return number;
    }

    void show()
    {
        cout << getName() << "的学号:" << getNumber() << endl;
    }

};

int main()
{
    Student st1;
    st1.setName("张三");
    st1.setNumber("24251102209");
    st1.show();


    system("pause");
    return 0;
}