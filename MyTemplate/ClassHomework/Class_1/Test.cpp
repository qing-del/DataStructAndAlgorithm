#include <cstdio>
using namespace std;
#define il inline

struct Node {
    int index;  // 底数
    int pow;    // 指数
    Node *next;
};

// 链表实现多项式相加
il void listAdd(Node* h1, Node* h2) {
    if (!h1 || !h2) return;
    Node* pre;
    while (h2) {
        while (h1->next && h2->pow > h1->pow) {
            pre = h1;
            h1 = h1->next;
        }

        if (!h1->next) {
            h1->next = h2;
            return;
        }

        // 指数过大就插入
        if (h1->pow > h2->pow) {
            pre->next = h2;
            h2 = h2->next;
            pre = pre->next;
            pre->next = h1;
        } else {    // 指数相等
            h1->index += h2->index;
            h2 = h2->next;
        }
    }
}