#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pair
{   
    int key;
    string val;
};

class HashMapChaining
{
    private:
        int size;                       //数量
        int capacity;                   //哈希表容量
        double loadThres;               //负载因子阈值
        int extendRatio;                //扩容倍数
        vector<vector<Pair *>> buckets; //桶数组

    public:
        HashMapChaining(): size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) {
            buckets.resize(capacity);
        }
        
        ~HashMapChaining(){
            for(auto &bucket : buckets)
            {
                for(Pair *pair : bucket) delete pair;
            }
        }

        int hashFunc(int key)
        {
            return key % capacity;
        }

        double loadThres()
        {
            return (double)size / (double)capacity;
        }

        string get(int key)
        {
            int index = hashFunc(key);
            for(Pair *pair : buckets[index])
            {
                if(pair->key == key)
                return pair->val;
            }
            return " ";
        }

        void put(int key, string val)
        {
            if(loadThres() > loadThres) extend();
            int index = hashFunc(key);
            for(Pair *pair : buckets[index])
            {
                if(pair->key == key)
                {
                    pair->val = val;
                    return;
                }
            }

            buckets[index].push_back(new Pair(key, val));
            size++;
        }

        void remove(int key)
        {
            int index = hashFunc(key);
            auto &bucket = buckets[index];

            for(int i = 0,n = bucket.size(); i < n; i++)
            {
                if(bucket[i]->key == key)
                {
                    Pair *tmp = bucket[i];
                    bucket.erase[bucket.begin() + i];
                    delete tep;     //在上一行代码中，只是删掉了数组的值，但是根本地在堆区删掉那一部分内存，所以需要创建一个临时指针指向要删除的数据，方便后续的释放内存
                    size--;
                    return;
                }
            }
        }

        void extend()
        {
            vecror<vector<Pair *>> bucketsTmp = buckets;
            capacity *= extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;

            for(auto &bucket : bucketsTmp)
            {
                for(Pair *pair : bucket)
                {
                    put(pair->key, pair->val);
                    delete pair;
                }
            }
        }

        void print()
        {
            for(auto &bucket : buckets)
            {
                cout << "[";
                for(Pair *pair : bucket)
                {
                    cout << pair->key << "-> " << pair->val << ", ";
                }
                cout << "]" << endl;
            }
        }
};