#include <iostream>
#include <string>
using namespace std;

//定义结构体
struct Student
{
    string name;
    int age;
    int score;
};

void hi(Student* stu);
void hi_array(Student stus[] , int len);

void hi(Student* stu)
{
    cout << stu->name << " " << stu->age << " " << stu->score << endl;
}

void hi_array(Student stus[] , int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << stus[i].name << " " << stus[i].age << " " << stus[i].score << endl;
    }
    
}


int main(void)
{
    //结构体默认创建
    struct Student stu1;
    stu1.name = "小一";
    cout << stu1.name << endl;

    //结构体带参创建
    struct Student stu2 = {"赵二" , 16 , 96};
    hi(&stu2);

    //结构体数组
    struct Student stuArray[3] =
    {
        {"张三", 18, 100},
        {"李四", 29, 99},
        {"王五", 25, 88}  // 初始化第三个学生，避免越界访问
    };
    
    stuArray[2].name = "李白";

    int len = sizeof(stuArray) / sizeof(stuArray[0]);
    hi_array(stuArray , len);

    
}