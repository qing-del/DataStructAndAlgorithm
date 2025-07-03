#include <iostream>
using namespace std;
#include <cstring>
#include <bitset>
#include <queue>

struct Node
{
    int i;
    int j;
    int step;
    Node(){}
    Node(int i, int j)
    {
        this->i = i;
        this->j = j;
    }
};

const int N = 4e2 + 5;
int a[N][N], start_i, start_j, n, m;
bitset<N> bit[N];

int x_i[] = { -2, -2, 1, -1, 2, 2, 1, -1 };
int y_j[] = { 1, -1, -2, -2, 1, -1, 2, 2 };

int Min(const int& a, const int& b) { return a < b ? a : b; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, -1, sizeof(a));
    cin >> n >> m >> start_i >> start_j;
    Node start(start_i, start_j);
    start.step = 0;
    queue<Node> q;
    q.push(start);
    bit[start_i].set(start_j);
    int step = 0;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        a[now.i][now.j] = now.step;
        for (int k = 0; k < 8; k++)
        {
            int i = now.i + x_i[k];
            int j = now.j + y_j[k];
            if (i <= 0 || i > n || j <= 0 || j > m) continue;
            else
                if (!bit[i][j])
                {
                    bit[i].set(j);
                    Node node(i, j);
                    node.step = now.step + 1;
                    q.push(node);
                }
        }

    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] >= 0) cout << a[i][j] << "    ";
            else cout << a[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}