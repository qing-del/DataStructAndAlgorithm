#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pair{
    int key;
    string val;

    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
};

class HashMapOpenAddressing
{
    private:
        int size;
        int capacity = 4;
        const double loadThres = 2.0 / 3.0;
        const int extendRatio = 2;
        vector<Pair *> buckets;
        Pair *TOMBSOME = new Pair(-1, "-1");

    public:
    HashMapOpenAddressing(): size(0), buckets(capacity, nullptr){}

    ~HashMapOpenAddressing()
    {
        for(Pair *pair : buckets)
        {
            if(pair != nullptr && pair != TOMBSOME)
            {
                delete pair;
            }
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

    int findBucket(int key)
    {
        int index = hashFunc(key);
        int firstTombstone = -1;
        while(buckets[index] != nullptr)
        {
            if(buckets[index]->key == key)
            {
                
            }
        }
    }
};