#include <iostream>
#include <string>
using namespace std;

class Pair
{
public:
    int key;
    string val;

    Pair(){}
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
    ~Pair(){}

    Pair operator+(const Pair& a)
    {
        return Pair(key+a.key,val + "+" + a.val);  //加号运算符重载
    }
};

int main()
{
    Pair p1(1,"iphone");
    Pair p2(2,"iqoo");
    Pair p3 = p1 + p2;
    cout << p3.key << " " << p3.val << endl;
    system("pause");
    return 0;
}