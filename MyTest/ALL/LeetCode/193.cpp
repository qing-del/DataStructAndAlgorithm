#include <bits/stdc++.h>
using namespace std;
//求搜索二叉树的LAC
//测试链接：https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q) {
        //说明此时p和q分布在root的两侧 此时的root即为p和q的LCA（ans）
        if (p->val <= root->val && root->val <= q->val)
            return root;
        //说明ans在root的左边
        else if (p->val < root->val && root->val > q->val)
            return f(root->left, p, q);
        //说明ans在root的右边
        else
            return f(root->right, p, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //使p和q之间的关系满足 p < q  充分使用搜索二叉树的特性
        if (p->val > q->val) {
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }
        // p < q 的特性
        return f(root, p, q);
    }
};