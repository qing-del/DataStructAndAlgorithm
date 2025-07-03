#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define S string

struct TreeNode
{
	char val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	TreeNode(char val)
	{
		this->val = val;
	}
	TreeNode(){}
};

void pre_run(const TreeNode* t)
{
	if (t == nullptr) return;
	cout << t->val;
	pre_run(t->left);
	pre_run(t->right);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	S s;
	cin >> n;
	cin >> s;
	TreeNode* root = new TreeNode(s[0]);
	if (s[1] != '*')
	{
		root->left = new TreeNode(s[1]);
	}
	if (s[2] != '*')
	{
		root->right = new TreeNode(s[2]);
	}

	TreeNode cur;

	for (int i = 1; i < n; i++)
	{
		cin >> s;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* cur = nullptr;

		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			if (cur->val == s[0]) break;
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}

		if (s[1] != '*')
		{
			cur->left = new TreeNode(s[1]);
		}

		if (s[2] != '*')
		{
			cur->right = new TreeNode(s[2]);
		}

	}

	pre_run(root);

	return 0;
}