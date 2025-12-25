#include <cstdio>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node() {}
	Node(int val) : val(val) {
	}
};

// 链表初始化
Node* initList() {
	return new Node();
}

// 在 pos 节点后插入 val 值的节点
bool insertById(Node* head, int pos, int val)
{
	if(head == NULL) return false;
	Node* cur = head;
	for(int i = 0; i < pos; i++)
	{
		cur = cur -> next;
		if(cur == NULL) return false;	//说明节点不存在，插入失败
	}
	
	Node* node = new Node(val);
	node->next = cur -> next;
	cur->next = node;
	return true;
}

// 删除 pos 位置的节点
void deleteById(Node* head, int pos)
{
	Node* pre = NULL;
	Node* cur = head;
	for(int i = 0; i < pos; i++)
	{
		pre = cur;
		cur = cur -> next;
		if(cur == NULL) return;	//说明 pos 节点不存在 直接返回
	}
	
	pre->next = cur->next;
	delete cur;
}

// 返回 pos 位置的节点
Node* searchByPos(Node* head, int pos)
{
	if(head == NULL) return NULL;
	Node* cur = head;
	for(int i=0;i<pos;i++)
	{
		cur = cur->next;
		if(cur == NULL) return cur; 
	}
	
	return cur;
}

// 返回 val 值的节点
Node* searchByVal(Node* head, int val)
{
	Node* cur = head;
	while(cur != NULL && cur->val != val)
		cur = cur->next;
	return cur->val == val ? cur : NULL;	
}
