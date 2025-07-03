#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define il inline
#define rg register

class HighPrecisionNumber {
private:
    vector<int> integer; // 整数部分
    vector<int> decimal; // 小数部分
    bool negative;       // 是否为负数

    // 去除前导零和后导零
    void trim() {
        while (integer.size() > 1 && integer.back() == 0) integer.pop_back();
        while (decimal.size() > 0 && decimal.back() == 0) decimal.pop_back();
    }

    // 对齐小数部分
    void alignDecimal(HighPrecisionNumber& other) {
        int maxDecimalSize = max(decimal.size(), other.decimal.size());
        decimal.resize(maxDecimalSize, 0);
        other.decimal.resize(maxDecimalSize, 0);
    }

public:
    // 构造函数
    HighPrecisionNumber(const string& s = "0") {
        negative = false;
        int pointPos = s.find('.');
        string intPart, decPart;

        if (pointPos == string::npos) {
            intPart = s;
            decPart = "";
        } else {
            intPart = s.substr(0, pointPos);
            decPart = s.substr(pointPos + 1);
        }

        // 处理符号
        if (intPart[0] == '-') {
            negative = true;
            intPart = intPart.substr(1);
        }

        // 整数部分
        for (int i = intPart.size() - 1; i >= 0; i--)
            integer.push_back(intPart[i] - '0');

        // 小数部分
        for (char c : decPart)
            decimal.push_back(c - '0');

        trim();
    }

    // 加法
    HighPrecisionNumber operator+(const HighPrecisionNumber& other) const {
        if (negative != other.negative) {
            HighPrecisionNumber tmp = other;
            tmp.negative = !tmp.negative;
            return *this - tmp;
        }

        HighPrecisionNumber result;
        result.negative = negative;

        // 对齐小数部分
        HighPrecisionNumber a = *this, b = other;
        a.alignDecimal(b);

        // 小数部分相加
        int carry = 0;
        for (int i = a.decimal.size() - 1; i >= 0; i--) {
            int sum = a.decimal[i] + b.decimal[i] + carry;
            result.decimal.insert(result.decimal.begin(), sum % 10);
            carry = sum / 10;
        }

        // 整数部分相加
        int maxIntSize = max(a.integer.size(), b.integer.size());
        for (int i = 0; i < maxIntSize; i++) {
            int sum = (i < a.integer.size() ? a.integer[i] : 0) +
                       (i < b.integer.size() ? b.integer[i] : 0) + carry;
            result.integer.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) result.integer.push_back(carry);

        result.trim();
        return result;
    }

    // 减法
    HighPrecisionNumber operator-(const HighPrecisionNumber& other) const {
        if (negative != other.negative) {
            HighPrecisionNumber tmp = other;
            tmp.negative = !tmp.negative;
            return *this + tmp;
        }

        HighPrecisionNumber result;
        HighPrecisionNumber a = *this, b = other;

        // 对齐小数部分
        a.alignDecimal(b);

        // 如果 a < b，交换并标记负号
        if (a.absLessThan(b)) {
            swap(a, b);
            result.negative = !negative;
        } else {
            result.negative = negative;
        }

        // 小数部分相减
        int borrow = 0;
        for (int i = a.decimal.size() - 1; i >= 0; i--) {
            int diff = a.decimal[i] - b.decimal[i] - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.decimal.insert(result.decimal.begin(), diff);
        }

        // 整数部分相减
        for (int i = 0; i < a.integer.size(); i++) {
            int diff = a.integer[i] - (i < b.integer.size() ? b.integer[i] : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.integer.push_back(diff);
        }

        result.trim();
        return result;
    }

    // 乘法
    HighPrecisionNumber operator*(const HighPrecisionNumber& other) const {
        HighPrecisionNumber result;
        result.negative = negative ^ other.negative;

        // 计算总位数
        int totalSize = integer.size() + decimal.size() + other.integer.size() + other.decimal.size();
        result.integer.resize(totalSize, 0);

        // 整数部分和小数部分统一计算
        for (int i = 0; i < integer.size() + decimal.size(); i++) {
            for (int j = 0; j < other.integer.size() + other.decimal.size(); j++) {
                int a = (i < integer.size() ? integer[i] : decimal[i - integer.size()]);
                int b = (j < other.integer.size() ? other.integer[j] : other.decimal[j - other.integer.size()]);
                result.integer[i + j] += a * b;
            }
        }

        // 处理进位
        int carry = 0;
        for (int i = 0; i < totalSize; i++) {
            int sum = result.integer[i] + carry;
            result.integer[i] = sum % 10;
            carry = sum / 10;
        }

        // 分离整数和小数部分
        int decimalPoint = decimal.size() + other.decimal.size();
        result.decimal.assign(result.integer.begin(), result.integer.begin() + decimalPoint);
        result.integer.erase(result.integer.begin(), result.integer.begin() + decimalPoint);

        result.trim();
        return result;
    }

    // 除法（暂不支持）
    HighPrecisionNumber operator/(const HighPrecisionNumber& other) const {
        throw runtime_error("Division not implemented");
    }

    // 绝对值比较
    bool absLessThan(const HighPrecisionNumber& other) const {
        if (integer.size() != other.integer.size())
            return integer.size() < other.integer.size();
        for (int i = integer.size() - 1; i >= 0; i--) {
            if (integer[i] != other.integer[i])
                return integer[i] < other.integer[i];
        }
        for (int i = 0; i < max(decimal.size(), other.decimal.size()); i++) {
            int a = (i < decimal.size() ? decimal[i] : 0);
            int b = (i < other.decimal.size() ? other.decimal[i] : 0);
            if (a != b) return a < b;
        }
        return false;
    }

    // 小于比较
    bool operator<(const HighPrecisionNumber& other) const {
        if (negative != other.negative) return negative;
        return negative ? other.absLessThan(*this) : absLessThan(other);
    }

    // 等于比较
    bool operator==(const HighPrecisionNumber& other) const {
        if (negative != other.negative) return false;
        return integer == other.integer && decimal == other.decimal;
    }

    // 输出
    void print() const {
        if (negative) cout << "-";
        for (int i = integer.size() - 1; i >= 0; i--)
            cout << integer[i];
        if (!decimal.empty()) {
            cout << ".";
            for (int i = 0; i < decimal.size(); i++)
                cout << decimal[i];
        }
        cout << "\n";
    }
};

int main() {
    HighPrecisionNumber a("123.45");
    HighPrecisionNumber b("67.89");

    cout << "Addition: ";
    (a + b).print();

    cout << "Subtraction: ";
    (a - b).print();

    cout << "Multiplication: ";
    (a * b).print();

    cout << "Comparison (a < b): " << (a < b) << "\n";
    cout << "Comparison (a == b): " << (a == b) << "\n";

    return 0;
}