#include <iostream>
using namespace std;
#include <string>
const int N = 20 + 3;
int n, twis, maxV;
string a[N], b[N];
char start;
short vis[N], ad[N][N]; //ad用于储存从第几位开始拼接，若其值为-1，即为无法拼接

int Max(const int& a, const int& b) { return a > b ? a : b; }

int check(const string& a, const string& b)
{
    int len = 1;
    int a_len = a.size();
    string c = b.substr(0, len);
    size_t found = a.rfind(c, a_len - 1);
    len = a_len - found;
    if (len == 1) return b.size() - len;
    c = b.substr(0, len);
    found = a.rfind(c, a_len - 1);
    if (found == string::npos) return 0;
    else
    {
        if (found == 0)
            return 0;
        else
            if (len == b.size()) return 0;
            else return b.size() - len;
    }
}

void dfs(int i, int ans)
{
    maxV = Max(maxV, ans);
    for (int j = 0; j < n; j++)
    {
        if (vis[j] < 2 && ad[i][j])
        {
            vis[j]++;
            dfs(j, ans + ad[i][j]);
            vis[j]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ad[i][j] = 0;
                continue;
            }
            ad[i][j] = check(a[i], a[j]);
        }
    }
    cin >> start;

    for (int i = 0; i < n; i++)
    {
        if (a[i].find(start, 0) == 0)
        {
            vis[i]++;
            dfs(i, a[i].size());
            vis[i]--;
        }
    }

    cout << maxV << endl;
    return 0;
}