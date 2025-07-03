#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

#define N 10
#define M_PI  3.14159265358979323846

double n, x0_val, y0_val, x1_val, y1_val, wide, high, square_1, x[N], y[N], r[N], max_ans;
bitset<N> used;

double min(double a, double b) { return a > b ? b : a; }
double max(double a, double b) { return a > b ? a : b; }
double get_mad(const int& i, const int& j) { return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); }
double juedui(const double& a, const double& b)
{
    if (a - b < 0) return -(a - b);
    return a - b;
}
double get_r(int i) { return min(min(juedui(y[i], y0_val), juedui(y[i], y1_val)), min(juedui(x[i], x0_val), juedui(x[i], x1_val))); }
double get_square(double r) { return r * r * M_PI; }

void dfs(int i, int step, double ans)
{
    r[i] = get_r(i);
    for (int j = 0; j < n; j++)
    {
        if (used.count() == 1) break;
        if (i == j) continue;
        if (r[i] < 0) break;
        if (used[j]) r[i] = min(r[i], sqrt(get_mad(i, j)) - r[j]);
    }
    if (r[i] > 0) ans += get_square(r[i]);
    if (step == n)
    {
        max_ans = max(max_ans, ans);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (!used[j])
        {
            used.set(j);
            dfs(j, step + 1, ans);
            used.reset(j);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    used.reset();
    cin >> n;
    cin >> x0_val >> y0_val >> x1_val >> y1_val;
    x0_val += 1000; y0_val += 1000; x1_val += 1000; y1_val += 1000;
    wide = juedui(y0_val, y1_val);
    high = juedui(x0_val, x1_val);
    square_1 = wide * high;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        x[i] += 1000;
        y[i] += 1000;
    }

    for (int i = 0; i < n; i++)
    {
        used.set(i);
        dfs(i, 1, 0);
        used.reset(i);
    }
    cout << fixed << setprecision(0) << square_1 - max_ans << endl;
    return 0;
}