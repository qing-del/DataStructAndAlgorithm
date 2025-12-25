// 链表实现多项式相加
#include <cstdio>
using namespace std;

struct Node{
	int val;	//系数值
	int index;	//指数值 （有序，由小到大）
	Node* next;
	Node() : val(0), index(0), next(NULL) {}
};

Node* listPlus(Node* p1, Node* p2)
{
	Node* head = new Node();
	
	head->next = p1;
	Node* cur = head->next;
	Node* pre = head;
	while(p2!=NULL)
	{
		while(cur != NULL && cur->index < p2->index)
		{
			pre = cur;
			cur = cur->next;
		}
		
		// 若是 cur 到了尾端 直接相接即可
		if(cur==NULL){
			pre->next = p2;
			break;
		}
		
		// 若是指数相等 直接相加值
		if(p2->index == cur->index) {
			cur->val += p2->val;
			// 删除指数相等的节点
			Node* tmp = p2;
			p2 = p2->next;
			delete tmp;
		}
		else
		{
			//跑到这里说明 cur 的节点指数更大
			//将节点插在 pre 之后即可
			Node* tmp = p2;
			p2 = p2->next;
			tmp->next = pre->next;
			pre->next = tmp;
			pre = tmp;
		} 
	}
	
	return head;
}
