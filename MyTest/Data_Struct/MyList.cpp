#include <iostream>
#include <vector>

using namespace std;

class MyList
{
    private :
        int * arr;              //数组
        int arrCapacity = 10;   //列表容量
        int arrSize = 0;        //列表长度
        int extendRatio = 2;    //扩序倍数
    
    public:
        MyList()
        {
            arr = new int[arrCapacity]; //开辟数组空间
        }

        ~MyList()
        {
            delete[] arr; //释放内存
        }

        int size()
        {
            return this->arrSize;
        }

        int capacity()
        {
            return this->arrCapacity;
        }

        int get(int index)
        {
            if (index < 0 || index >= arrCapacity)  //检测是否越界
                throw out_of_range("索引越界");
            return arr[index];
        }

        void set(int index, int num)
        {
            if (index < 0 || index >= arrCapacity)  //检测是否越界
                throw out_of_range("索引越界");
            arr[index] = num;
        }

        void add(int num)
        {
            if (size() == arrCapacity)  //扩容机制
                extendCapacity();
            arr[size()] = num;
            arrSize++;
        }

        void insert(int index, int num)
        {
            if (index < 0 || index >= arrCapacity - 1)  //检测是否越界
                throw out_of_range("索引越界");
            for (int i = size(); i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = num;
        }

        //删除元素，并返回它的值
        int remove(int index)
        {
            if (index < 0 || index >= arrCapacity)  //检测是否越界
                throw out_of_range("索引越界");
            int num = arr[index];
            for (int i = index; i < size() - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arrSize--;
            return num;
        }

        //扩容
        void extendCapacity()
        {
            int newCapacity = capacity() * extendRatio;
            int * tem = arr;
            arr = new int[newCapacity];

            for (int i = 0; i < size(); i++)
            {
                arr[i] = tem[i];
            }
            delete[] tem;
            arrCapacity = newCapacity;
        }

        vector<int> toVector()
        {
            vector<int> vec(size());
            for (int i = 0; i < size(); i++)
            {
                vec[i] = arr[i];
            }
            return vec;
        }
};