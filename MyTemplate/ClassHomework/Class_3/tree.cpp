#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

struct node {
	int val;
	node* left;
	node* right;
};

struct qnode {
	node* root;
	int d;

	qnode(node* root = NULL, int d = 0) : root(root), d(d) {}
};

node* build(const string& str, int& i)
{
	if (str[i] == '#') {
		i++;
		return NULL;
	}

	node* root = new node();
	root->val = str[i++];

	root->left = build(str, i);
	root->right = build(str, i);

	return root;
}

int Max(int a, int b) { return a > b ? a : b; }

void prePrint(node* root)
{
	if (!root) return;
	cout << (char)root->val << " ";
	prePrint(root->left);
	prePrint(root->right);
}

void midPrint(node* root)
{
	if (!root) return;
	prePrint(root->left);
	cout << (char)root->val << " ";
	prePrint(root->right);
}

void lasPrint(node* root)
{
	if (!root) return;
	prePrint(root->left);
	prePrint(root->right);
	cout << (char)root->val << " ";
}

int countNode(node* root)
{
	if (!root) return 0;
	return countNode(root->left) + countNode(root->right) + 1;
}

int countLeaf(node* root)
{
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	return countLeaf(root->left) + countLeaf(root->right);
}

int countHeight(node* root)
{
	if (!root) return 0;
	return Max(countHeight(root->left), countHeight(root->right)) + 1;
}

void countWidthHelp(node* root, vector<int>& cnt, int d)
{
	if (!root) return;
	cnt[d]++;
	countWidthHelp(root->left, cnt, d + 1);
	countWidthHelp(root->right, cnt, d + 1);
}

int countWidth(node* root)
{
	int n = countHeight(root);
	vector<int> cnt(n, 0);
	countWidthHelp(root, cnt, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = Max(ans, cnt[i]);
	return ans;
}

int countWidthBfs(node* root)
{
	int ans = 0;
	queue<qnode> q;
	q.push(qnode(root, 0));
	vector<int> cnt(countHeight(root), 0);
	while (q.size())
	{
		qnode cur = q.front();
		q.pop();
		cnt[cur.d]++;
		ans = Max(ans, cnt[cur.d]);
		if (cur.root->left) q.push(qnode(cur.root->left, cur.d + 1));
		if (cur.root->right) q.push(qnode(cur.root->right, cur.d + 1));
	}
	return ans;
}

int main()
{
	string str;
	//cin >> str;
	str = "ABC##DE#G##F###";
	int i = 0;
	node* root = build(str, i);

	prePrint(root);
	cout << endl;
	midPrint(root);
	cout << endl;
	lasPrint(root);
	cout << endl;

	cout << "node num:" << countNode(root) << endl;
	cout << "tree height:" << countHeight(root) << endl;
	cout << "tree max width num:" << countWidth(root) << endl;
	return 0;
}