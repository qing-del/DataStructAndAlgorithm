#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define il inline
#define rg register
const int N = 502;

class BigInt {
public:
    int arr[N]; // 第零位不能放数字
    int size;
    bool nagetive; // 是否为负数

    // 构造函数
    BigInt(const string& s = "0")
    {
        size = s.size();
        int len = size;
        if (s[0] == '-') nagetive = true, size--;
        else nagetive = false;
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= size; i++)
            arr[i] = s[len - i] - '0';
    }

    // 加法
    void add(const BigInt& x)
    {
        if (nagetive != x.nagetive) // 符号不同，转换为减法
        {
            BigInt tmp = x;
            tmp.nagetive = !tmp.nagetive;
            subtract(tmp);
            return;
        }

        size = max(size, x.size);
        for (int i = 1; i <= x.size; i++)
        {
            arr[i] += x.arr[i];
            if (arr[i] >= 10)
            {
                arr[i] -= 10;
                arr[i + 1]++;
            }
        }
        if (arr[size + 1]) size++;
    }

    // 减法
    void subtract(const BigInt& x)
    {
        if (nagetive != x.nagetive) // 符号不同，转换为加法
        {
            BigInt tmp = x;
            tmp.nagetive = !tmp.nagetive;
            add(tmp);
            return;
        }

        if (absLessThan(x)) // 如果当前数绝对值小于 x，交换并标记负号
        {
            BigInt tmp = *this;
            *this = x;
            subtract(tmp);
            nagetive = !nagetive;
            return;
        }

        for (int i = 1; i <= size; i++)
        {
            arr[i] -= x.arr[i];
            if (arr[i] < 0)
            {
                arr[i] += 10;
                arr[i + 1]--;
            }
        }
        while (size > 1 && arr[size] == 0) size--; // 去除前导零
    }

    // 乘法
    void multiply(const BigInt& x)
    {
        BigInt res;
        res.size = size + x.size;
        res.nagetive = nagetive ^ x.nagetive; // 符号位异或

        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= x.size; j++)
                res.arr[i + j - 1] += arr[i] * x.arr[j];

        for (int i = 1; i <= res.size; i++)
        {
            if (res.arr[i] >= 10)
            {
                res.arr[i + 1] += res.arr[i] / 10;
                res.arr[i] %= 10;
            }
        }

        while (res.size > 1 && res.arr[res.size] == 0) res.size--; // 去除前导零
        *this = res;
    }

    // 除法（整除）
    void divide(const BigInt& x)
    {
        if (x.isZero()) throw runtime_error("Division by zero");

        BigInt res, current;
        res.size = size;
        res.nagetive = nagetive ^ x.nagetive; // 符号位异或

        for (int i = size; i >= 1; i--)
        {
            current.shiftLeft();
            current.arr[1] = arr[i];
            while (!current.absLessThan(x))
            {
                current.subtract(x);
                res.arr[i]++;
            }
        }

        while (res.size > 1 && res.arr[res.size] == 0) res.size--; // 去除前导零
        *this = res;
    }

    // 左移一位（乘以 10）
    void shiftLeft()
    {
        for (int i = size; i >= 1; i--)
            arr[i + 1] = arr[i];
        arr[1] = 0;
        size++;
    }

    // 判断是否为零
    bool isZero() const
    {
        return size == 1 && arr[1] == 0;
    }

    // 绝对值比较：当前数是否小于 x
    bool absLessThan(const BigInt& x) const
    {
        if (size != x.size) return size < x.size;
        for (int i = size; i >= 1; i--)
            if (arr[i] != x.arr[i])
                return arr[i] < x.arr[i];
        return false;
    }

    // 小于比较
    bool operator<(const BigInt& x) const
    {
        if (nagetive != x.nagetive) return nagetive;
        return nagetive ? x.absLessThan(*this) : absLessThan(x);
    }

    // 输出
    void Println() const
    {
        if (nagetive) cout << "-";
        for (int i = size; i >= 1; i--)
            cout << arr[i];
        cout << "\n";
    }

    void Print() const
    {
        if (nagetive) cout << "-";
        for (int i = size; i >= 1; i--)
            cout << arr[i];
    }
};