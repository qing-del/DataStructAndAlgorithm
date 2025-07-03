#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 4;
int pi[] = { 1,-1,0,0 }, pj[] = { 0,0,1,-1 };
int n, m, a, b, x, y, v[N][N];

struct Node
{
    int i, j, cnt;
    Node(int i, int j, int cnt)
    {
        this->i = i;
        this->j = j;
        this->cnt = cnt;
    }
};

void bfs()
{
    queue<Node> q;
    q.push(Node(x, y, 0));
    while (!q.empty())
    {
        Node p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ii = p.i + pi[k], jj = p.j + pj[k];
            if (ii<1 || jj<1 || ii>n || jj>m) continue;
            if (v[ii][jj] == -1 || p.cnt + 1 < v[ii][jj])
            {
                v[ii][jj] = p.cnt + 1;
                q.push(Node(ii, jj, p.cnt + 1));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(v, -1, sizeof(v));
    cin >> n >> m >> a >> b;
    while (a--)
    {
        cin >> x >> y;
        v[x][y] = 0;
        bfs();
    }
    while (b--)
    {
        cin >> x >> y;
        cout << v[x][y] << endl;
    }
    return 0;
}