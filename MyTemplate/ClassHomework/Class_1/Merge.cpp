// 有序表的合并（由小到大）
#include <cstdio>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node() : next(NULL) {}
	Node(int val) : val(val), next(NULL) {}
};

// 顺序表实现 （n 为 a 的长度，m 为 b 的长度）
int* merge(int* a, int n, int* b, int m)
{
	int s = n + m;
	int* arr = new int[s];
	int i = 0, j = 0, k = 0;
	while(i < n && j < m)
	{
		if(a[i] <= b[j])
			arr[k++] = a[i++];
		else
			arr[k++] = b[j++];
	}
	
	while(i < n)
		arr[k++] = a[i++];
		
	while(j < m)
		arr[k++] = b[j++];
		
	return arr;
}


// 链表实现
Node* merge(Node* p1, Node* p2)
{
	Node* head = NULL;
	Node* cur = head;
	//选择一个头节点
	if(p1->val <= p2->val)
	{
		cur = p1;
		p1 = p1->next;
	}
	else
	{
		cur = p2;
		p2 = p2->next;
	}
	
	head = cur;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->val <= p2->val)
		{
			cur->next = p1;
			p1 = p1->next;
		}
		else
		{
			cur->next = p2;
			p2 = p2->next;
		}
		cur = cur->next;
	}
	
	cur->next = p1 != NULL ? p1 : p2;
	
	return head;
}
