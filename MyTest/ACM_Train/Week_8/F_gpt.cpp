#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 504, M = 10004;
string No = "impossible";
int n, m, k, dis[N][N];
struct edge {
    int u, v, w;
} e[M];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dis[i][j] = INF; // 初始化距离
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    dis[1][0] = 0;

    for (int step = 1; step <= k; step++) {
        for (int i = 1; i <= m; i++) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if (dis[u][step - 1] < INF) {
                dis[v][step] = min(dis[v][step], dis[u][step - 1] + w);
            }
        }
    }

    int result = INF;
    for (int step = 0; step <= k; step++) {
        result = min(result, dis[n][step]);
    }

    if (result == INF) {
        cout << No << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}