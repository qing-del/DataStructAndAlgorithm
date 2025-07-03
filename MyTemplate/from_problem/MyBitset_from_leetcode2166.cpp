#include <iostream>
#include <string>
#include <bitset>
#include <random>
using namespace std;
const int N = 1e5 + 10;
bitset<N> a;

class Bitset {
    int size, n;
    int* bit;
    int onen, zero;
    bool reverse = 0;   //没有反转

    inline void ownUnfix(const int& idx) {
        if (!getBit(idx)) return;
        bit[idx / 32] &= ~(1 << (idx % 32));
        onen--, zero++;
    }

    inline void ownFix(const int& idx) {
        if (getBit(idx)) return;
        bit[idx / 32] |= 1 << (idx % 32);
        onen++, zero--;
    }

    inline bool getBit(const int& idx) {
        return (bit[idx / 32] >> (idx % 32)) & 1;
    }

    inline bool operator[](const int& idx) {
        return (bit[idx / 32] >> (idx % 32) & 1) ^ reverse;
    }



public:
    Bitset(int size) {
        this->size = (size + 31) / 32;
        n = size;
        bit = new int[this->size];
        /*for (int i = 0; i < this->size; i++)
            bit[i] = 0;*/
        memset(bit, 0, this->size * sizeof(int));
        onen = 0, zero = n;
    }

    ~Bitset() {
        delete[] bit;
    }

    inline void fix(int idx) {
        if (reverse){
            ownUnfix(idx);
            return;
        }
        if (getBit(idx)) return;
        bit[idx / 32] |= 1 << (idx % 32);
        onen++, zero--;
    }

    inline void unfix(int idx) {
        if (reverse) {
            ownFix(idx);
            return;
        }
        if (!getBit(idx)) return;
        bit[idx / 32] &= ~(1 << (idx % 32));
        onen--, zero++;
    }

    inline void flip() {
        reverse = !reverse;
    }

    inline bool all() {
        return (reverse ? zero == n : onen == n);
    }

    inline bool one() {
        return (reverse ? zero : onen);
    }

    inline int count() {
        return (reverse ? zero : onen);
    }

    inline string toString() {
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += (*this)[i] ? "1" : "0";
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int op[N], arr[N], n, m;
bool ac;

inline int rdi(const int& l, const int& r)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}

void serach_wa()
{
    int T; cin >> T;
    cout << "begin test...\n";
    while (T--)
    {
        a.reset();
        n = rdi(10, 100);
        Bitset b(n);
        m = rdi(10, 100);
        for (int i = 0; i < m; i++)
        {
            op[i] = rdi(1, 7);  //获得操作指令
            if (op[i] == 1)
            {
                arr[i] = rdi(0, n - 1);
                a[arr[i]] = 1;
                b.fix(arr[i]);
            }
            else if (op[i] == 2)
            {
                arr[i] = rdi(0, n - 1);
                a[arr[i]] = 0;
                b.unfix(arr[i]);
            }
            else if (op[i] == 3)
            {
                arr[i] = -1;
                a = ~a;
                b.flip();
            }
            else if (op[i] == 4)
            {
                if (a.all() != b.all())
                {
                    cout << op[i] << "\n";
                    cout << "Wrong Answer!\n" << n << " " << m << "\n";
                    return;
                }
            }
            else if (op[i] == 5)
            {
                if (!a.none() != b.one())
                {
                    cout << op[i] << "\n";
                    cout << "Wrong Answer!\n" << n << " " << m << "\n";
                    return;
                }
            }
            else if (op[i] == 6)
            {
                if (a.count() - N + n != b.count())
                {
                    cout << op[i] << "\n";
                    cout << "Wrong Answer!\n" << n << " " << m << "\n";
                    return;
                }
            }
            else
            {
                if (a.to_string() != b.toString())
                {
                    if (a.count() != b.count())
                    {
                        cout << op[i] << "\n";
                        cout << "Wrong Answer!\n" << n << " " << m << "\n";
                        return;
                    }
                }
            }
        }
    }
    ac = 1;
    cout << "Accepted!\n";
}

inline void nextStep() 
{
    if (ac) return;
    a.reset();
    Bitset b(n);
    for (int i = 0; i < m; i++)
    {
        if (op[i] == 1)
        {
            a[arr[i]] = 1;
            b.fix(arr[i]);
        }
        else if (op[i] == 2)
        {
            a[arr[i]] = 0;
            b.unfix(arr[i]);
        }
        else if (op[i] == 3)
        {
            arr[i] = -1;
            a = ~a;
            b.flip();
        }
        else if (op[i] == 4)
        {
            if (a.all() != b.all())
                cout << a.all() << " " << b.all() << "\n";
        }
        else if (op[i] == 5)
        {
            if (!a.none() != b.one())
                cout << !a.none() << " " << b.one() << "\n";
        }
        else if (op[i] == 6)
        {
            if (a.count() - N + n != b.count())
                cout << a.count() << " " << b.count() << "\n";
        }
        else
        {
            if (a.to_string().substr(0,n) != b.toString())
                cout << a.to_string().substr(0, n) << "\n" << b.toString() << "\n";
        }
    }
}

inline void Test()
{
    Bitset b(5); // 初始: [0, 0, 0, 0, 0]
    b.flip();    // 反转: [1, 1, 1, 1, 1] (逻辑位)
    b.unfix(0);  // 设置第0位为0 (逻辑位: [0, 1, 1, 1, 1])
    cout << b.count() << endl; // 正确应为4，原代码输出错误
}

int main()
{
    //serach_wa();
    //nextStep();
    Test();
    return 0;
}