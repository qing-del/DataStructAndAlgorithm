#include <bits/stdc++.h>
using namespace std;
#define IOS_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ms(x,n) memset(x,n,sizeof(x))
#define ull unsigned long long
#define ll long long
#define il inline
#define rg register
const int N = 1e5 + 2;
const int K = 10;
int n, k, len[N];
ull ans, T[N];  // T记录出现的次数
int maxn;        // 找出最大值

struct node {
    ull freq;
    int id;
    int high;
    node* child[K];

    node(int id = 0, ull freq = 0, int high = 0) {
        this->id = id;
        this->freq = freq;
        this->high = high;
        ms(child, 0);
    }
};

struct Compare {
    bool operator() (node* a, node* b) {
        if (a->freq != b->freq) return a->high > b->high;
        return a->freq > b->freq; // 小顶堆
    }
};

priority_queue<node*, vector<node*>, Compare> q;

il int Max(const int& a, const int& b) { return a > b ? a : b; }

il node* Build() {   // 构建哈夫曼树
    while ((q.size() - 1) % (k - 1) != 0) q.push(new node(0, 0));

    while (q.size() > 1) {
        node* now = new node(-1, 0);
        for (int i = 0; i < k && !q.empty(); i++) { // 确保每次合并 k 个节点
            node* x = q.top();
            q.pop();
            maxn = Max(maxn, x->high);
            now->child[i] = x;
            now->freq += x->freq;
        }
        now->high = maxn + 1;
        q.push(now);
    }

    node* root = q.top();
    return root;
}


il void getLen(node* root, int code) {
    if (root == nullptr) return;

    if (root->id != -1) { // 叶子节点
        if (root->id != 0)   // 忽略虚拟节点
            ans += code * T[root->id];
        
        return;
    }

    for (int i = 0; i < k; i++) {
        getLen(root->child[i], code + 1);
    }
}

//il ull getAns() {
//    ans = 0, maxn = 0;
//    for (int i = 1; i <= n; i++) {
//        ans += T[i] * len[i];
//        maxn = Max(maxn, len[i]);
//    }
//    return ans;
//}

il void read() {
    IOS_IO;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        q.push(new node(i, T[i], 0));
    }
}

int main() {
    IOS_IO;
    read();
    node* root = Build();
    getLen(root, 0);
    rg int high = q.top()->high;
    cout << ans << "\n" << high << "\n";
    return 0;
}