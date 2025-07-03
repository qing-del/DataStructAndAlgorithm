#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pair
{
    public :
        int key;
        string val;
        
        Pair(int key, string val)
        {
            this->key = key;
            this->val = val;
        }
};

class ArrayHashMap
{
    private:
        vector<Pair *> buckets; //是一个指针数组

    public:
        ArrayHashMap(){
            buckets = vector<Pair *>(100);  //初始化100个桶(储存的是指针)
        }

        ~ArrayHashMap(){
            //释放内存
            for(const auto &bucket : buckets){
                delete bucket;
            }
            buckets.clear();
        }

        //哈希函数（100个桶）
        int hashFunc(int key){
            return key % 100;
        }

        string get(int key){
            int index = hashFunc(key);
            Pair *pair= buckets[index];
            if (pair == nullptr)
            {
                return " ";
            }
            return pair->val;
        }

        void put(int key, string val){
            Pair *pair = new Pair(key, val);    //开辟空间
            int index = hashFunc(key);
            buckets[index] = pair;
        }

        void remove(int key){
            int index = hashFunc(key);
            //释放内存并置为 nullptr
            delete buckets[index];
            buckets[index] = nullptr;
        }

        //获取所有键值对
        vector<Pair *> pairSet(){
            vector<Pair *> pairSet;
            for(Pair *pair : buckets){               
                if (pair != nullptr)
                {
                    pairSet.push_back(pair);
                }                
            }
            return pairSet;
        }

        //获取所有值
        vector<string> valueSet(){
            vector<string> valueSet;
            for(Pair *pair : buckets){
                if(pair != nullptr){
                    valueSet.push_back(pair->val)
                }
            }
            return valueSet;
        }

        void print(){
            for(Pair *kv : pairSet()){
                cout << kv->key << "->" << kv->val << endl;
            }
        }
};