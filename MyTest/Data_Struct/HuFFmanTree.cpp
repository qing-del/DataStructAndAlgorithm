#include <bits/stdc++.h>
using namespace std;
#define IOSIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define il inline
#define rg register
int n, m;

struct HNode {
	double weight;	//权值
	HNode* left;	//左孩子指针
	HNode* right;	//右孩子指针
	char val;		//存的字符
	
	HNode(char val, double freq = 0) : val(val), weight(freq), left(nullptr), right(nullptr) {}

	bool operator < (const HNode& x) const
	{
		return x.weight < weight;
	}
};

struct Compare {
	bool operator()(HNode* a, HNode* b) {
		return a->weight > b->weight; // 小顶堆
	}
};
priority_queue<HNode*, vector<HNode*>, Compare> q;	//优先队列（小顶堆）

il void read()
{
	for (int i = 0; i < n; i++)
	{
		rg char val;
		rg int freq;
		cin >> val >> freq;
		q.push(new HNode(val, freq));
	}
}

il HNode* Build()
{
	while(q.size()>1)
	{
		HNode* left = q.top(); q.pop();
		HNode* right = q.top(); q.pop();
		HNode* node = new HNode('\0', left->weight + right->weight);
		node->left = left;
		node->right = right;
		q.push(node);
	}
	HNode* root = q.top();
	q.pop();
	return root;
}

il void PrintHuffTree(HNode* root, string s)
{
	if (root==nullptr) return;
	if (root->left == nullptr && root->right == nullptr)
		cout << root->val << "  " << s << "\n";
	if (root->left != nullptr) PrintHuffTree(root->left, s + "0");
	if (root->right != nullptr) PrintHuffTree(root->right, s + "1");
}

int main()
{
	IOSIO;
	cin >> n;
	read();
	HNode* root = Build();
	
	PrintHuffTree(root, "");

	return 0;
}