#include <iostream>
#include <string>
using namespace std;
#include <ctime>

struct Student 
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    string tName;
    struct Student team[5]; 
};

void allocateSpace();
void Print(const Teacher t);

//给老师和学生赋值
void allocateSpace(struct Teacher t[] ,int len)
{
    string nameSeed = "ABCDE";
    for(int i = 0; i < len ; i++)
    {
        t[i].tName = "Teacher_";
        t[i].tName += nameSeed[i];

        for(int j = 0;j < 5;j++)
        {
            t[i].team[j].name = "Student_";
            t[i].team[j].name += nameSeed[j];

            int random = rand() % 61 + 40;
            t[i].team[j].score = random;
        }
    }
}

//打印老师和所带学生的信息
void Print(const Teacher t[] , int len)
{
    for(int i = 0;i < len ; i++)
    {
        cout << "老师姓名：" << t[i].tName << endl;
        cout << "\t其所带的学生：" << endl;
        for(int j = 0;j < 5;j++)
        {
            cout << "\t姓名：" << t[i].team[j].name << "  " << "成绩:" << t[i].team[j].score << endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    //创建三名老师
    struct Teacher tArray[3];

    //通过函数赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray , len);

    //打印所有老师和所带学生的信息
    Print(tArray , len);

    return 0;
}