#include <iostream>
#include <string>
using namespace std;
#define MAX 1000  //ͨѶ¼������

struct AddressPerson
{
    int sex; //�Ա�
    string name; //����
    int age;  //����
    string number;  //��ϵ�绰
    string addr; //��ͥסַ
};

struct AdsBook
{
    struct AddressPerson pArray[MAX];

    int m_Size;
};

//�������
void Begein();
void PrintMenu();
void Operate(int n , bool& end , struct AdsBook * ads);
void Quit_Directory(bool& end); //�˳�ͨѶ¼
//��ϵ�˵Ĳ���
void AddPerson(struct AdsBook * ads);
void PrintInfo(const struct AdsBook* ads); //��ʾ������ϵ��
void DeletePerson(struct AdsBook * ads); //ɾ����ϵ��
void SearchPerson(const struct AdsBook * ads); //������ϵ��
void RevisePerson(struct AdsBook * ads); //�޸���ϵ��
void ClearPerson(struct AdsBook * ads); //�����ϵ��
//ϵͳ����
int isExist(const struct AdsBook * ads); //�Ƿ������ϵ��
void System_Delete(struct AdsBook * ads , int index); //ϵͳ����ɾ������
void System_Revise(struct AdsBook * ads , int index); //ϵͳ�޸�

void Begein()
{
    cout << "��ӭ����ͨѶ¼ϵͳ������7���Բ鿴�����˵���" << endl;
}

void PrintMenu()
{
    cout << "[0.�����ϵ��]" << endl;
    cout << "[1.��ʾ������ϵ��]"  << endl;
    cout << "[2.ͨ������ɾ����ϵ��]"  << endl;
    cout << "[3.ͨ������������ϵ��]"  << endl;
    cout << "[4.ͨ�������޸���ϵ����Ϣ]"  << endl;
    cout << "[5.�����ϵ��]"  << endl;
    cout << "[6.�˳�ͨѶ¼ϵͳ]"  << endl;
    
}

//�����ж�
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
        cout << "û�����ֲ���" << endl;
    }
}

//�˳�����
void Quit_Directory(bool& end)
{
    end = true;
    cout << "�˳��ɹ���" << endl;
    cout << "��ӭ�´�ʹ�ã�" << endl;
}

//�����ϵ��
void AddPerson(struct AdsBook * ads)
{
    if (ads->m_Size == MAX)
    {
        cout << "ͨѶ¼����" << endl;
        return;
    } else {
        cout << "������������" << endl;
        cin >> ads->pArray[ads->m_Size].name; 

        cout << "���������䣺" << endl;
        cin >> ads->pArray[ads->m_Size].age;

        while(true)
        {
            cout << "�������Ա���1��Ů2����" << endl;
            cin >> ads->pArray[ads->m_Size].sex;
            if(ads->pArray[ads->m_Size].sex != 1 && ads->pArray[ads->m_Size].sex != 2 )
            {
                cout << "û�д��Ա�����������" << endl;
            } else
            {
                break;
            }
        }

        cout << "��������ϵ���룺" << endl;
        cin >> ads->pArray[ads->m_Size].number;

        cout << "�������ͥסַ��" << endl;
        cin >> ads->pArray[ads->m_Size].addr;

        ads->m_Size++;
        cout << "��ӳɹ���" << endl;

    }
}

//��ʾ������ϵ��
void PrintInfo(const struct AdsBook * ads)
{
    if(ads->m_Size == 0)
    {
        cout << "ĿǰͨѶ¼Ϊ��" << endl;
    } else {
        for(int i = 0; i < ads->m_Size ; i++)
        {
            if(i != 0)
            {
                cout << endl;
            }
            cout << "������" << ads->pArray[i].name << endl;
            cout << "�Ա�" << (ads->pArray[i].sex == 1 ? "��" : "Ů") << endl; 
            cout << "���䣺" << ads->pArray[i].age << endl; 
            cout << "��ϵ�绰��" << ads->pArray[i].number << endl; 
            cout << "��ͥסַ��" << ads->pArray[i].addr << endl;
        }
    }
}

//ɾ������
void DeletePerson(struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "���޴���" << endl;
        return;
    }

    cout << "\t������ϢΪ�£�" << endl;
    cout << "������" << ads->pArray[m].name << endl;
    cout << "�Ա�" << (ads->pArray[m].sex == 1 ? "��" : "Ů") << endl; 
    cout << "���䣺" << ads->pArray[m].age << endl; 
    cout << "��ϵ�绰��" << ads->pArray[m].number << endl; 
    cout << "��ͥסַ��" << ads->pArray[m].addr << endl;
    cout << endl;

    int require;
    cout << "�Ƿ�ִ��ɾ�������������� 1 �ٴ�ȷ����" << endl;
    cin >> require;

    if (require == 1)
    {
        System_Delete(ads,m);
    }
} 

//������ϵ��
void SearchPerson(const struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "���޴���" << endl;
        return;
    }

    cout << "������ϢΪ�£�" << endl;
    cout << "������" << ads->pArray[m].name << endl;
    cout << "�Ա�" << (ads->pArray[m].sex == 1 ? "��" : "Ů") << endl; 
    cout << "���䣺" << ads->pArray[m].age << endl; 
    cout << "��ϵ�绰��" << ads->pArray[m].number << endl; 
    cout << "��ͥסַ��" << ads->pArray[m].addr << endl;
}

//�޸ķ���
void RevisePerson(struct AdsBook * ads)
{
    int m = isExist(ads);
    if(m == -1)
    {
        cout << "���޴���" << endl;
        return;
    }

    cout << "������ϢΪ�£�" << endl;
    cout << "������" << ads->pArray[m].name << endl;
    cout << "�Ա�" << (ads->pArray[m].sex == 1 ? "��" : "Ů") << endl; 
    cout << "���䣺" << ads->pArray[m].age << endl; 
    cout << "��ϵ�绰��" << ads->pArray[m].number << endl; 
    cout << "��ͥסַ��" << ads->pArray[m].addr << endl;

    int require;
    cout << "�Ƿ�ִ���޸Ĳ����������� 1 �ٴ�ȷ����" << endl;
    cin >> require;

    if (require == 1)
    {
        System_Revise(ads,m);
    }
}

//�����ϵ��
void ClearPerson(struct AdsBook * ads)
{
    cout << "�Ƿ����ͨѶ¼�������� 1 �ٴ�ȷ�ϣ�" << endl;

    int introduct;
    cin >> introduct;
    if(introduct == 1)
    {
        ads->m_Size = 0;
        cout << "ͨѶ¼����գ�" << endl;
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



//�ж��Ƿ���ڴ���
int isExist(const struct AdsBook * ads)
{
    string name;
    cout << "������Ҫ��������ϵ�˵�����" << endl;
    cin >> name;

    if(ads->m_Size == 0)
    {
        cout << "ͨѶ¼Ϊ��!" << endl;
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

//ϵͳɾ������
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
    cout << "ɾ����ϣ�" << endl;
}

//ϵͳ�޸�
void System_Revise(struct AdsBook * ads , int index)
{
    cout << "���ڿ�ʼ�����޸���Ϣ" << endl;
    cout << "������������" << endl;
    cin >> ads->pArray[ads->m_Size].name; 

    cout << "���������䣺" << endl;
    cin >> ads->pArray[ads->m_Size].age;

    while(true)
    {
        cout << "�������Ա���1��Ů2����" << endl;
        cin >> ads->pArray[ads->m_Size].sex;
        if(ads->pArray[ads->m_Size].sex != 1 && ads->pArray[ads->m_Size].sex != 2 )
        {
            cout << "û�д��Ա�����������" << endl;
        } else
        {
            break;
        }
    }

    cout << "��������ϵ���룺" << endl;
    cin >> ads->pArray[ads->m_Size].number;

    cout << "�������ͥסַ��" << endl;
    cin >> ads->pArray[ads->m_Size].addr;
}