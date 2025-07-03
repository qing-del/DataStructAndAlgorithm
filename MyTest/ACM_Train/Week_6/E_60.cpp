#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <queue>
#define N 15
string A[N], B[N], a, b, C[N];
int n;
bool is_output = 0;
map<int, int> m;

void bfs(string ans, int step)
{
    if (step != 0)
        if (ans == C[step - 1])
            return;
    if (is_output) return;
    if (step > 10) return;
    if (step != 0 && ans == a) return; //剪枝（成环）
    C[step] = ans;
    string temp = ans;
    if (ans == b)
    {
        is_output = 1;
        cout << step << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (is_output) break;
        if (m[i] == 1) continue;
        size_t found = ans.find(A[i], 0);
        if (found != string::npos)
        {
            m[i] = 1;
            ans.replace(found, A[i].size(), B[i]);
            bfs(ans, step + 1);
            m[i] = 0;
            ans = temp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    while (cin >> A[n] >> B[n] && n < 6)
        n++;
    if (n == 0 && a != b)
    {
        cout << "NO ANSWER!" << endl;
        return 0;
    }
    bfs(a, 0);
    if (!is_output) cout << "NO ANSWER!" << endl;
    return 0;
}