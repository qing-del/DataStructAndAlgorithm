#include <iostream>
#include <string>
using namespace std;
#define MAX 1000  //通讯录的容量

struct AddressPerson
{
    int sex; //性别
    string name; //姓名
    int age;  //年龄
    string number;  //联系电话
    string addr; //家庭住址
};

struct AdsBook
{
    struct AddressPerson pArray[MAX];

    int m_Size;
};

//界面操作
void Begein();
void PrintMenu();
void Operate(int n , bool& end , struct AdsBook * ads);
void Quit_Directory(bool& end); //退出通讯录
//联系人的操作
void AddPerson(struct AdsBook * ads);
void PrintInfo(const struct AdsBook* ads); //显示所有联系人
void DeletePerson(struct AdsBook * ads); //删除联系人
void SearchPerson(const struct AdsBook * ads); //查找联系人
void RevisePerson(struct AdsBook * ads); //修改联系人
void ClearPerson(struct AdsBook * ads); //清空联系人
//系统操作
int isExist(const struct AdsBook * ads); //是否存在联系人
void System_Delete(struct AdsBook * ads , int index); //系统单个删除操作
void System_Revise(struct AdsBook * ads , int index); //系统修改

void Begein()
{
    cout << "欢迎来到通讯录系统（输入7可以查看帮助菜单）" << endl;
}

void PrintMenu()
{
    cout << "[0.添加联系人]" << endl;
    cout << "[1.显示所有联系人]"  << endl;
    cout << "[2.通过姓名删除联系人]"  << endl;
    cout << "[3.通过姓名查找联系人]"  << endl;
    cout << "[4.通过姓名修改联系人信息]"  << endl;
    cout << "[5.清空联系人]"  << endl;
    cout << "[6.退出通讯录系统]"  << endl;
    
}

//操作判定
void Operate(int n , struct AdsBook* ads , bool& end)
{
    cin >> n;
    switch (n)
    {
    case 0:
        AddPerson(ads);
        break;
    case 1:
        PrintInfo(ads);
        break;
    case 2:
        DeletePerson(ads);
        break;
    case 3:
        SearchPerson(ads);
        break;
    case 4:
        RevisePerson(ads);
        break;
    case 5:
        ClearPerson(ads);
        break;
    case 6:
        Quit_Directory(end);
        break;
    case 7:
        PrintMenu();
        break;
    default:
        cout << "没有这种操作" << endl;
    }
}

//退出方法
void Quit_Directory(bool& end)
{
    end = true;
    cout << "退出成功！" << endl;
    cout << "欢迎下次使用！" << endl;
}

//添加联系人
void AddPerson(struct AdsBook * ads)
{
    if (ads->m_Size == MAX)
    {
        cout << "通讯录已满" << endl;
        return;
    } else {
        cout << "请输入姓名：" << endl;
        cin >> ads->pArray[ads->m_Size].name; 

        cout << "请输入年龄：" << endl;
        cin >> ads->pArray[ads->m_Size].age;

        while(true)
        {
            cout << "请输入性别（男1，女2）：" << endl;
            cin >> ads->pArray[ads->m_Size].sex;
            if(ads->pArray[ads->m_Size].sex != 1 && ads->pArray[ads->m_Size].sex != 2 )
            {
                cout << "没有此性别请重新输入" << endl;
            } else
            {
                break;
            }
        }

        cout << "请输入联系号码：" << endl;
        cin >> ads->pArray[ads->m_Size].number;

        cout << "请输入家庭住址：" << endl;
        cin >> ads->pArray[ads->m_Size].addr;

        ads->m_Size++;
        cout << "添加成功！" << endl;

    }
}

//显示所有联系人
void PrintInfo(const struct AdsBook * ads)
{
    if(ads->m_Size == 0)
    {
        cout << "目前通讯录为空" << endl;
    } else {
        for(int i = 0; i < ads->m_Size ; i++)
        {
            if(i != 0)
            {
                cout << endl;
            }
            cout << "姓名：" << ads->pArray[i].name << endl;
            cout << "性别：" << (ads->pArray[i].sex == 1 ? "男" : "女") << endl; 
            cout << "年龄：" << ads->pArray[i].age << endl; 
            cout << "联系电话：" << ads->pArray[i].number << endl; 
            cout << "家庭住址：" << ads->pArray[i].addr << endl;
        }
    }
}

//删除方法
void DeletePerson(struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "查无此人" << endl;
        return;
    }

    cout << "\t此人信息为下：" << endl;
    cout << "姓名：" << ads->pArray[m].name << endl;
    cout << "性别：" << (ads->pArray[m].sex == 1 ? "男" : "女") << endl; 
    cout << "年龄：" << ads->pArray[m].age << endl; 
    cout << "联系电话：" << ads->pArray[m].number << endl; 
    cout << "家庭住址：" << ads->pArray[m].addr << endl;
    cout << endl;

    int require;
    cout << "是否执行删除操作？（输入 1 再次确定）" << endl;
    cin >> require;

    if (require == 1)
    {
        System_Delete(ads,m);
    }
} 

//查找联系人
void SearchPerson(const struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "查无此人" << endl;
        return;
    }

    cout << "此人信息为下：" << endl;
    cout << "姓名：" << ads->pArray[m].name << endl;
    cout << "性别：" << (ads->pArray[m].sex == 1 ? "男" : "女") << endl; 
    cout << "年龄：" << ads->pArray[m].age << endl; 
    cout << "联系电话：" << ads->pArray[m].number << endl; 
    cout << "家庭住址：" << ads->pArray[m].addr << endl;
}

//修改方法
void RevisePerson(struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "查无此人" << endl;
        return;
    }

    cout << "此人信息为下：" << endl;
    cout << "姓名：" << ads->pArray[m].name << endl;
    cout << "性别：" << (ads->pArray[m].sex == 1 ? "男" : "女") << endl; 
    cout << "年龄：" << ads->pArray[m].age << endl; 
    cout << "联系电话：" << ads->pArray[m].number << endl; 
    cout << "家庭住址：" << ads->pArray[m].addr << endl;

    int require;
    cout << "是否执行修改操作？（输入 1 再次确定）" << endl;
    cin >> require;

    if (require == 1)
    {
        System_Revise(ads,m);
    }
}

//清空联系人
void ClearPerson(struct AdsBook * ads)
{
    cout << "是否清空通讯录？（输入 1 再次确认）" << endl;

    int introduct;
    cin >> introduct;
    if(introduct == 1)
    {
        ads->m_Size = 0;
        cout << "通讯录已清空！" << endl;
    }
}



int main()
{
    bool end = false;
    int operater = -1;
    AdsBook ads;
    ads.m_Size = 0;

    while(!end)
    {
        Begein();
        Operate(operater , &ads , end);

        system("pause");
        system("cls");
    }

    return 0;
}



//判断是否存在此人
int isExist(const struct AdsBook * ads)
{
    string name;
    cout << "请输入要操作的联系人的名字" << endl;
    cin >> name;

    if(ads->m_Size == 0)
    {
        cout << "通讯录为空!" << endl;
        return -1;
    } else {
        for(int i = 0; i < ads->m_Size; i++)
        {
            if (ads->pArray[i].name == name)
            {
                return i;
            }
            
        }
        return -1;
    }
}

//系统删除操作
void System_Delete(struct AdsBook * ads , int index)
{
    ads->m_Size--;
    for(int i = index ; i < ads->m_Size ; i++)
    {
        ads->pArray[i].name = ads->pArray[i + 1].name;   
        ads->pArray[i].age = ads->pArray[i + 1].age;
        ads->pArray[i].sex = ads->pArray[i + 1].sex;
        ads->pArray[i].addr = ads->pArray[i + 1].addr;
        ads->pArray[i].number = ads->pArray[i + 1].number;
    }
    cout << "删除完毕！" << endl;
}

//系统修改
void System_Revise(struct AdsBook * ads , int index)
{
    cout << "现在开始输入修改信息" << endl;
    cout << "请输入姓名：" << endl;
    cin >> ads->pArray[ads->m_Size].name; 

    cout << "请输入年龄：" << endl;
    cin >> ads->pArray[ads->m_Size].age;

    while(true)
    {
        cout << "请输入性别（男1，女2）：" << endl;
        cin >> ads->pArray[ads->m_Size].sex;
        if(ads->pArray[ads->m_Size].sex != 1 && ads->pArray[ads->m_Size].sex != 2 )
        {
            cout << "没有此性别请重新输入" << endl;
        } else
        {
            break;
        }
    }

    cout << "请输入联系号码：" << endl;
    cin >> ads->pArray[ads->m_Size].number;

    cout << "请输入家庭住址：" << endl;
    cin >> ads->pArray[ads->m_Size].addr;
}