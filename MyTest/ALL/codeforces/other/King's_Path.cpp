#include <bits/stdc++.h>
using namespace std;

#define IOS_IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int start_x, start_y, end_x, end_y;
map<int, vector<pii>> rows; // 存储每行的允许列区间
set<pii> visited;

struct Node {
    int x, y, step;
    Node(int x = 0, int y = 0, int step = 0) : x(x), y(y), step(step) {}
    bool operator<(const Node& other) const {
        int cost1 = step + abs(x - end_x) + abs(y - end_y);
        int cost2 = other.step + abs(other.x - end_x) + abs(other.y - end_y);
        return cost1 > cost2; // 小顶堆
    }
};

bool isAllowed(int x, int y) {
    auto it = rows.find(x);
    if (it == rows.end()) return false;
    for (auto& interval : it->second) {
        if (y >= interval.fi && y <= interval.se) {
            return true;
        }
    }
    return false;
}

int main() {
    IOS_IO;
    cin >> start_x >> start_y >> end_x >> end_y;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r, a, b;
        cin >> r >> a >> b;
        rows[r].pb(mp(a, b));
    }

    priority_queue<Node> pq;
    pq.push(Node(start_x, start_y, 0));
    visited.insert(mp(start_x, start_y));

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.x == end_x && curr.y == end_y) {
            cout << curr.step << endl;
            return 0;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (visited.count(mp(nx, ny)) continue;
            if (!isAllowed(nx, ny)) continue;
            visited.insert(mp(nx, ny));
            pq.push(Node(nx, ny, curr.step + 1));
        }
    }

    cout << -1 << endl;
    return 0;
}