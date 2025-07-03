#include <bits/stdc++.h>
using namespace std;
#define il inline

//基本都用递归实现 为了AVL树做基础

struct TreeNode {
	int val;
	int height;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val = 0, int height = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) :
		val(val), height(height), left(left), right(right) {}
};

il int Max(int a, int b) { return a > b ? a : b; }

//获取节点高度
il int get_height(TreeNode* node)
{
	return node != nullptr ? node->height : -1;
}

//更新树高
il void update_height(TreeNode* node)
{
	node->height = Max(get_height(node->left), get_height(node->right)) + 1;
}

//获取平衡因子
il int get_balance_factor(TreeNode* node)
{
	return get_height(node->left) - get_height(node->right);
}

//右旋并更新高度 返回新的根节点
il TreeNode* RightRotate(TreeNode* node)
{
	TreeNode* child = node->left;
	TreeNode* granchild = child->right;

	child->right = node;
	node->left = granchild;

	update_height(node);
	update_height(child);

	return child;	//新的根节点
}

//左旋并更新高度 返回新的根节点
il TreeNode* LeftRotate(TreeNode* node)
{
	TreeNode* child = node->right;
	TreeNode* granchild = child->left;

	child->left = node;
	node->right = granchild;

	update_height(node);
	update_height(child);

	return child;	//新的根节点
}

//平衡操作
il TreeNode* Rotate(TreeNode* node)
{
	int f = get_balance_factor(node);
	if (f >= -1 && f <= 1)	//平衡状态
		return node;

	if (f > 1)	//即为 L
	{
		int c = get_balance_factor(node->left);
		if (c >= 0)	//LL
			node = RightRotate(node);
		else	//LR
		{
			node->left = LeftRotate(node->left);
			node = RightRotate(node);
		}
	}
	else
	{
		int c = get_balance_factor(node->right);
		if (c <= 0)	//RR
			node = LeftRotate(node);
		else	//RL
		{
			node->right = RightRotate(node->right);
			node = LeftRotate(node);
		}
	}
	return node;
}

//递归插入	并且自动对树进行平衡操作
il TreeNode* insert(TreeNode* node, const int& val)
{
	if (node == nullptr)	//可以存放值的空节点
		return new TreeNode(val);

	if (val > node->val)
		node->right = insert(node->right, val);
	else if (val < node->val)
		node->left = insert(node->left, val);
	
	update_height(node);
	return Rotate(node);
}

//删除节点	并返回平衡之后的根节点
il TreeNode* remove(TreeNode* node, const int& val)
{
	if (nullptr == node)	//不存在该节点
		return nullptr;
	
	if (val > node->val)
		node->right = remove(node->right, val);
	else if (val < node->val)
		node->left = remove(node->left, val);
	else
		if (nullptr == node->left || nullptr == node->right)
		{
			TreeNode* child = (nullptr != node->left ? node->left : node->right);
			if (nullptr == child)
			{
				delete node;
				return nullptr;
			}
			else
			{
				delete node;
				return child;
			}
		}
		else
		{
			TreeNode* cur = node->right;
			while (nullptr != cur->left)
				cur = cur->left;
			node->val = cur->val;
			node->right = remove(node->right, node->val);
		}
	update_height(node);
	return Rotate(node);
}

il TreeNode* search(TreeNode* node, const int& val)
{
	if (nullptr == node)	//不存在该节点
		return nullptr;

	if (val > node->val)
		return search(node->right, val);
	else if (val < node->val)
		return search(node->left, val);
	else
		return node;	//找到该节点
}


int main()
{
	int n, m; cin >> n >> m;
	TreeNode* root = nullptr;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		root = insert(root, x);
	}

	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		root = remove(root, x);
	}

	queue<TreeNode*> q;
	queue<int> h;
	h.push(1);
	q.push(root);
	int H = 1;
	while(q.size())
	{
		TreeNode* t = q.front();
		int high = h.front();
		q.pop(); h.pop();

		if (high > H)
		{
			cout << "\n";
			H++;
		}
		cout << t->val << " ";
		if (t->left != nullptr)
			h.push(high + 1), q.push(t->left);
		if (t->left != nullptr)
			h.push(high + 1), q.push(t->right);

	}

	return 0;
}