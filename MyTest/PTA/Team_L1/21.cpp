#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pair
{
    int key;

    Pair(int key)
    {
        this->key = key;
    }
};

class HashMap //储存朋友圈中出现过的人
{
    private:
        vector<Pair *> bruckets;
        vector<bool> book;
    public:
        HashMap()
        {
            bruckets.resize(100000);
            book.resize(100000, false);
        }

        ~HashMap(){
            for(auto c : bruckets)
            {
                if(c != nullptr) delete c;
            }
        }

        void put(int key)
        {
            if(bruckets[key] != nullptr) return;
            Pair *pair = new Pair(key);
            bruckets[key] = pair;
        }

        bool check(int key) //检查是否有这个人
        {
            if(bruckets[key] == nullptr) return false;
            if(bruckets[key]->key == key) return true;
            return false;
        }

        bool is_output(int key)
        {
            return book[key];
        }

        void revise(int key)
        {
            book[key] = true;
        }

        
};

int main()
{
    int N;
    cin >> N;
    HashMap m;
    for(int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for(int j = 0; j < K; j++)
        {
            string input;
            cin >> input;
            m.put(stoi(input));
        }
    }
    int M;
    cin >> M;
    int count = 0;
    for(int i = 0; i < M; i++)
    {
        string context;
        cin >> context;
        if(!(m.check(stoi(context)))) 
        {
            if(!(m.is_output(stoi(context))))
            {
                if(count != 0) cout << " ";
                count++;
                cout << context;
                m.revise(stoi(context));
            }
        }
    }

    if(count == 0) cout << "No one is handsome";
    cout << endl;
    system("pause");
    return 0;
}